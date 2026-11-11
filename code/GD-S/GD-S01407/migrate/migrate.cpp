#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

auto getAllWays(const std::vector<int>& migrate, const int& d, std::vector<int>& __long, int buff, const int& start, const int& end) -> void
{
	if (start == end)
	{
		__long.emplace_back(buff);
		
		return;
	}
	
	for (auto i = start + 1; i <= end; ++i)
	{
		if (std::abs(migrate[i] - migrate[start]) <= d)
		{
			getAllWays(migrate, d, __long, buff + 1, i, end);
		}
	}
}

auto main() -> int
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	auto c = 0, t = 0;
	std::cin >> c >> t;
	
	while ((t--) > 0)
	{
		auto n = 0, d = 0;
		std::cin >> n >> d;
		
		auto migrate = std::vector<int>(n);
		
		for (auto i = 0; i < n; ++i)
		{
			std::cin >> migrate[i];
		}
		
		auto result = 0;
		
		for (auto i = 0; i < n - 2; ++i)
		{
			for (auto j = i + 2; j < n; ++j)
			{
				auto __long = std::vector<int>();
				getAllWays(migrate, d, __long, 0, i, j);
				
				auto minnest = *std::min_element(__long.begin(), __long.end());
				auto count = 0;
				
				for (const auto& __num : __long)
				{
					if (__num == minnest)
					{
						++count;
					}
				}
				
				if (count == 2)
				{
					++result;
				}
			}
		}
		
		std::cout << result << '\n';
	}
	
	return 0;
}
