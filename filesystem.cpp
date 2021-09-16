#include <iostream>
#include <filesystem>

int main() {
	std::filesystem::path str("C:\\Users\\16901\\Desktop\\1");
	if (!exists(str))		//必须先检测目录是否存在才能使用文件入口.
		return 1;
	std::filesystem::directory_entry entry(str);		//文件入口
	if (entry.status().type() == std::filesystem::file_type::directory)	//这里用了C++11的强枚举类型
		std::cout << "该路径是一个目录" << std::endl;
	std::filesystem::directory_iterator list(str);	        //文件入口容器
	for (auto& it : list)
		std::cout << it.path().filename() << std::endl;	//通过文件入口（it）获取path对象，再得到path对象的文件名，将之输出

	std::filesystem::create_directories("C:\\Users\\16901\\Desktop\\1\\a\\b\\c\\d");//形如/a/b/c这样的，如果都不存在，创建目录结构
	std::filesystem::create_directory("C:\\Users\\16901\\Desktop\\1\\abc");// 当目录不存在时创建目录

	std::cout<<std::filesystem::absolute("./")<<std::endl;//获取当前目录绝对路径
	std::cout << std::filesystem::file_size("C:\\Users\\16901\\Desktop\\1\\abc") << std::endl;//获取当前目录大小

	std::cout<<std::filesystem::remove_all("C:\\Users\\16901\\Desktop\\1\\a")<<std::endl;//递归删除目录下所有文件，返回被成功删除的文件个数
	system("pause");
	return 0;
}
