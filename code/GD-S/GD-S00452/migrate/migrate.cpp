#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
//	std::clock_t stTime = std::clock();

	std::freopen("migrate.in", "r", stdin);
	std::freopen("migrate.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int c, t;
	std::cin >> c >> t;

	auto solve = [&]() -> void {
		int n; i64 m;
		std::cin >> n >> m;

		std::vector<i64> x(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> x[i];
		}

		if (n <= 8000) {
			std::vector<std::tuple<int, int, int>> stk;
			u32 head = 0;
			i64 ans = 0;
			stk.reserve(n);
			for (int u = 0; u < n; ++u) {
				head = 0, stk.clear();
				stk.emplace_back(u, 0, 1);
				for (int v = u + 1; v < n; ++v) {
					while (head < stk.size() && x[v] - x[std::get<0>(stk[head])] > m) {
						++head;
					}
					if (head == stk.size()) {
						break;
					}
					auto d = std::get<1>(stk[head]) + 1;
					auto c = std::get<2>(stk[head]) + 0;
					for (int i = 1; head + i < stk.size() && d - 1 == std::get<1>(stk[head + i]) && c < 3; ++i) {
						c += std::get<2>(stk[head + i]);
					}
					c = std::min(c, 3);
					if (c == 2) {
						++ans;
					}
//					std::cerr << u << " " << v << " " << d << " " << c << "\n";
					while (!stk.empty() && std::get<1>(stk.back()) > d) {
						stk.pop_back();
					}
					stk.emplace_back(v, d, c);
				}
			}
			std::cout << ans << "\n";
		} else {
			std::cout << "0\n";
		}
	};

	for (int i = 0; i < t; ++i) {
		solve();
	}

//	std::cerr << 1. * (std::clock() - stTime) / CLOCKS_PER_SEC << "\n";

	return 0;
}

/*
freopen	--- 0
integer	--- 0
corner	--- 0
limit   --- 0

time	--- 0
memory	--- 0

duipai	--- 0
*/
