#include <iostream>
#include <string>
#include <fstream>

auto main() -> int
{	
	std::ifstream in("string.in");
	std::ofstream out("string.out", std::ios::trunc);
	
	auto n = 0;
	in >> n;
	
	auto input_str = std::string{ "" };
	
	for (auto i = 1; i <= n; ++i)
	{
		auto buff = 0LL;
		auto ch = '0';
		in >> buff >> ch;
		
		for (auto j = 1; j <= buff; ++j)
		{
			input_str += ch;
		}
	}
	
	auto result = 0LL;
	auto front = 0uLL;
	auto back = input_str.size() - 1;
	
	while (front < back)
	{
		if (input_str[front++] != input_str[back--])
		{
			++result;
		}
	}
	
	out << result << '\n';
	
	return 0;
}
