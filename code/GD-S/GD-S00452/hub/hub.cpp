#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
//	std::clock_t stTime = std::clock();

	std::freopen("hub.in", "r", stdin);
	std::freopen("hub.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int c, t;
	std::cin >> c >> t;

	auto solve = [&]() -> void {
		int n, k;
		std::cin >> n >> k;

		std::vector<std::vector<int>> adj(n);
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			std::cin >> u >> v;
			--u, --v;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}

		if (k <= 2) {
			std::vector<std::vector<int>> dist(n, std::vector<int>(n, -1));
			for (int s = 0; s < n; ++s) {
				std::queue<int> que;
				dist[s][s] = 0, que.push(s);
				while (!que.empty()) {
					auto u = que.front();
					que.pop();
					for (auto v : adj[u]) {
						if (dist[s][v] == -1)  {
							dist[s][v] = dist[s][u] + 1;
							que.push(v);
						}
					}
				}
			}
			int ans = n;
			for (int u = 0; u < n; ++u) {
				for (int v = 0; v < n; ++v) {
					int res = 0;
					for (int k = 0; k < n; ++k) {
						res = std::max(res, std::min(dist[u][k], dist[v][k]));
					}
					ans = std::min(ans, res);
				}
			}
			std::cout << ans << "\n";
		} else {
			std::vector<int> h(n);
			int lo = -1, hi = n;
			auto check = [&](int d) -> bool {
				auto calc = [&](int x, int p) -> int {
					int cnt = k + 1;
					auto dfs = [&](auto&& self, int u, int par) -> void {
						std::fill(h.begin(), h.end(), 0);
						int res = 0;
						auto dfs = [&](auto&& self, int u, int par) -> void {
							for (auto v : adj[u]) {
								if (v != par && v != p) {
									self(self, v, u);
									h[u] = std::max(h[u], h[v] + 1);
								}
							}
							res += (h[u] >= d || par == -1);
						};
						dfs(dfs, u, -1);
						cnt = std::min(cnt, res);
						for (auto v : adj[u]) {
							if (v != par) {
								self(self, v, u);
							}
						}
					};
					dfs(dfs, x, p);
					return cnt;
				};
				for (int x = 0; x < n; ++x) {
					for (auto y : adj[x]) {
						if (x < y) {
							if (calc(x, y) + calc(y, x) <= k) {
								return true;
							}
						}
					}
				}
				return false;
			};
			while (lo + 1 < hi) {
				auto mid = (lo + hi) >> 1;
				if (check(mid)) {
					hi = mid;
				} else {
					lo = mid;
				}
			}
			std::cout << hi << "\n";
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
