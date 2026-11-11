#include <algorithm>
#include <iostream>
#include <vector>

const int N = 507, M = 5e5 + 7;
typedef long long i64;

std::vector<std::pair<int,int>> g[M];
i64 dist[N][N];

int c, n, m, d, q;
int w[M];

auto upd = [](auto& x, auto&& y) { x = std::min(x, y); };

inline void solve() {
	std::cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i) { std::cin >> w[i]; }
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			dist[i][j] = i == j ? 0 : 1e18;
	for(int i = 1; i <= n; ++i) {
		int k; std::cin >> k;
		for(int j = 1; j <= k; ++j) {
			int a; i64 t; std::cin >> a >> t;
			for(auto& [x, y]: g[a]) upd(dist[i][x], t + y);
			g[a].emplace_back(i, t);
		}
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			dist[i][j] = dist[j][i] = std::min(dist[i][j], dist[j][i]);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) 
			for(int k = 1; k <= n; ++k)
				upd(dist[i][j], dist[i][k] + dist[k][j]);
	for(int x, y; q--; ) {
		std::cin >> x >> y;
		i64 add = w[x] + w[y];
		i64 tmp = 1e18;
		for(auto& [a, b]: g[x])
			for(auto& [c, d]: g[y])
				upd(tmp, dist[a][c] + b + d);
		std::cout << tmp + add << "\n";
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	solve();
}
