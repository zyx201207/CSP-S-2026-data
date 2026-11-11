#include <bits/stdc++.h>

const int N = 500 + 7, M = 5e5 + 7;

int _, n, m, d, q;
long long w[M];
std::vector<std::pair<int, long long>> p[M];
long long e[N][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::cin.tie(0), std::cout.tie(0), std::ios::sync_with_stdio(false);
	
	std::cin >> _ >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
		std::cin >> w[i];
	for (int i = 1, k; i <= n; ++i) {
		std::cin >> k;
		for (int j = 1, a, t; j <= k; ++j)
			std::cin >> a >> t, p[a].emplace_back(i, t);
	}
	memset(e, 0x3f, sizeof e);
	for (int i = 1; i <= n; ++i)
		e[i][i] = 0;
	for (int i = 1; i <= m; ++i)
		for (auto [u, t] : p[i])
			for (auto [v, s] : p[i])
				e[u][v] = std::min(e[u][v], s + t);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				e[j][k] = std::min(e[j][k], e[j][i] + e[i][k]);
	for (int i = 1, u, v; i <= q; ++i) {
		std::cin >> u >> v;
		long long ans = 1e18;
		for (auto [x, t] : p[u])
			for (auto [y, s] : p[v])
				ans = std::min(ans, s + t + e[x][y]);
		std::cout << (ans + w[u] + w[v]) << '\n';
	}
	return 0;
}
