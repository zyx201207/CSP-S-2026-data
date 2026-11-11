#include <iostream>
#include <vector>
#include <fstream>

auto getResult(const std::vector<std::vector<int>>& results, int i) -> int
{
	auto result = 0;
	
	for (const auto& __list : results)
	{
		for (const auto& num : __list)
		{
			if (num == i)
			{
				++result;
			}
		}
	}
	
	return result;
}

auto find(const std::vector<int>& src, int temp) -> int
{
	for (auto i = 0; i < src.size(); ++i)
	{
		if (src[i] == temp)
		{
			return i;
		}
	}
	
	return -1;
}

auto count(const std::vector<int>& cards, int _i) -> std::vector<int>
{
	auto result = std::vector<int>();
	
	for (auto i = _i; i <= cards.size(); ++i)
	{
		auto idx = find(result, cards[i]);
				
		if (idx != -1)
		{
			result.erase(result.begin() + idx, result.end());
		}
		
		result.emplace_back(cards[i]);
	}
	
	return result;
}

auto main() -> int
{
	std::ifstream in("card.in");
	std::ofstream out("card.out", std::ios::trunc);
	
	auto n = 0, m = 0;
	in >> n >> m;
	
	auto cards = std::vector<int>(n + 1);
	
	for (auto i = 1; i <= n; ++i)
	{
		in >> cards[i];
	}
	
	auto results = std::vector<std::vector<int>>(n + 1);
	
	for (auto i = 1; i <= n; ++i)
	{
		results[i] = count(cards, i);
	}
	
	for (auto i = 1; i <= m; ++i)
	{
		out << getResult(results, i) << ' ';
	}
	out << '\n';
	
	return 0;
}
