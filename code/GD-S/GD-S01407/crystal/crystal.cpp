#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

auto getResult(const std::vector<unsigned long long>& list, long long m) -> int
{
	auto result = 0;
	auto idx = 0uLL;
	
	while (m > 0 || idx < list.size())
	{
		m -= list[idx++];
		
		if (m >= 0)
		{
			++result;
		}
	}
	
	return result;
}

auto main() -> int
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	auto n = 0;
	auto m = 0uLL;
	std::cin >> n >> m;
	
	auto a = std::vector<long long>(n + 1);
	
	for (auto i = 1; i <= n; ++i)
	{
		std::cin >> a[i];
	}
	
	auto result = -1;
	
	for (auto i = n; i > 1; --i)
	{
		auto num = a[i];
		auto list = std::vector<unsigned long long>();

		for (auto j = 1; j <= n; ++j)
		{
			if (a[j] > num || j == i)
			{
				continue;
			}

			list.emplace_back(num - a[j]);
		}
		
		if (list.empty())
		{
			continue;
		}
		
		std::sort(list.begin(), list.end());
		
		result = std::max(result, getResult(list, m));
	}
	
	std::cout << result + 1 << '\n';
	
	return 0;
}
