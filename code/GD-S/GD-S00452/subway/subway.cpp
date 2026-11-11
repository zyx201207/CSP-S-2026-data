#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr i64 inf = 1ll << 60;

int main() {
	// std::clock_t stTime = std::clock();

	std::freopen("subway.in", "r", stdin);
	std::freopen("subway.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int c, n, m, d, q;
	std::cin >> c >> n >> m >> d >> q;

	std::vector<i64> w(m);
	for (int i = 0; i < m; ++i) {
		std::cin >> w[i];
	}

	std::vector<std::vector<std::pair<int, i64>>> vec(m);
	for (int i = 0; i < n; ++i) {
		int k;
		std::cin >> k;
		for (int j = 0; j < k; ++j) {
			int a; i64 t;
			std::cin >> a >> t; --a;
			vec[a].emplace_back(i, t);
		}
	}

	std::vector<std::vector<i64>> dist(
		n, 
		std::vector<i64>(
			n, 
			inf
		)
	);
	for (int u = 0; u < n; ++u) {
		dist[u][u] = 0;
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 1; j < int(vec[i].size()); ++i) {
			for (int k = 0; k < j; ++k) {
				auto const& u = std::get<0>(vec[i][j]);
				auto const& v = std::get<0>(vec[i][k]);
				i64 t = std::get<1>(vec[i][j]) + std::get<1>(vec[i][k]);
				dist[u][v] = std::min(dist[u][v], t);
				dist[v][u] = std::min(dist[v][u], t);
			}
		}
	}
	for (int k = 0; k < n; ++k) {
		for (int u = 0; u < n; ++u) {
			for (int v = 0; v < n; ++v) {
				dist[u][v] = std::min(dist[u][v], dist[u][k] + dist[k][v]);
			}
		}
	}

	for (int i = 0; i < q; ++i) {
		int x, y;
		std::cin >> x >> y;
		--x, --y;
		i64 ans = inf;
		for (auto const& vx : vec[x]) {
			auto const& u = std::get<0>(vx);
			auto const& ut = std::get<1>(vx);
			for (auto const& vy : vec[y]) {
				auto const& v = std::get<0>(vy);
				auto const& vt = std::get<1>(vy);
				ans = std::min(ans, dist[u][v] + ut + vt + w[x] + w[y]);
			}
		}
		std::cout << ans << "\n";
	}

	// std::cerr << 1. * (std::clock() - stTime) / CLOCKS_PER_SEC << "\n";

	return 0;
}

/*
freopen	--- 1
integer	--- 1
corner	--- 0 none (x != y)
limit   --- 0

time	--- 0 O(n ** 3 + (m + q) * d ** 2) /// 1s
memory	--- 0 8n ** 3 + 32 ** \sum k + 8m  /// 1024MB

duipai	--- 0
*/