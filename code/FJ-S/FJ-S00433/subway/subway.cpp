#include <bits/stdc++.h>

constexpr int M = 5e5 + 10, M2 = 1e3 + 10;
int z[M], a[M], t[M], dis[M], f[M2][M2];
bool vis[M];
std::vector<std::pair<int, int>> G[M];

void dijkstra(int s) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;

	std::priority_queue<std::pair<int, int>> pq;
	pq.emplace(0, s);

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (vis[u]) continue;
		vis[u] = true;

		for (auto p : G[u]) {
			int v = p.first, w = p.second;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				pq.emplace(-dis[v], v);
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	std::cin.tie(nullptr)->sync_with_stdio(false);

	int C, n, m, d, q;
	std::cin >> C >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) std::cin >> z[i];

	if (7 <= C && C <= 11) {
		memset(f, 0x3f, sizeof(f));
		for (int i = 1; i <= m; i++) f[i][i] = 0;

		for (int i = 1; i <= n; i++) {
			int k, a1, t1, a2, t2;
			std::cin >> k >> a1 >> t1 >> a2 >> t2;
      
			f[a1][a2] = f[a2][a1] = std::min(f[a1][a2], t1 + t2);
		}

		for (int k = 1; k <= m; k++)
			for (int i = 1; i <= m; i++)
				for (int j = 1; j <= m; j++) f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);

		while (q--) {
			int u, v;
			std::cin >> u >> v;

			std::cout << z[u] + f[u][v] + z[v] << '\n';
		}

		return 0;
	}

	for (int i = 1; i <= n; i++) {
		int k;
		std::cin >> k;

		for (int j = 1; j <= k; j++) {
			std::cin >> a[j] >> t[j];

			G[a[j]].emplace_back(m + i, t[j]);
			G[m + i].emplace_back(a[j], t[j]);
		}
	}

	while (q--) {
		int u, v;
		std::cin >> u >> v;

		dijkstra(u);

		std::cout << z[u] + dis[v] + z[v] << '\n';
	}
}
