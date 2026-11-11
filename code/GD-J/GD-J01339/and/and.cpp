#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

auto main() -> int
{
	std::ifstream in("and.in");
	std::ofstream out("and.out", std::ios::trunc);
	
	auto n = 0, m = 0;
	in >> n >> m;
	
	auto list = std::vector<int>(n + 1);
	
	for (auto i = 1; i <= n; ++i)
	{
		in >> list[i];
	}
	
	if (m == 1)
	{
		out << *std::max_element(list.begin(), list.end()) << '\n';
	}
	else if (m == 2)
	{
		std::sort(list.begin(), list.end());
		
		out << (list[list.size() - 1] & list[list.size() - 2]) << '\n';
	}
	
	out << list[1] << '\n';
	
	return 0;
}
