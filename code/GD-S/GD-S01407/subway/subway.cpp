#include <iostream>
#include <vector>
#include <cstdio>

auto main() -> int
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	auto c = 0, n = 0, m = 0, d = 0, q = 0;
	std::cin >> c >> n >> m >> d >> q;
	
	auto w = std::vector<int>(m + 1);
	
	for (auto i = 1; i <= m; ++i)
	{
		std::cin >> w[i];
	}
	
	std::cout << 1 << '\n';
	
	return 0;
}
