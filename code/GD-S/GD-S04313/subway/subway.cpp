#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1e18;

i64 dijkstra(const std::vector<std::vector<std::array<int, 2>>> &adj, int x, int y) {
	std::vector<i64> d(adj.size(), inf);
	std::vector<bool> st(adj.size(), 0);
	std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> q;
	d[x] = 0;
	q.push({0, x});
	while (!q.empty()) {
		int u = q.top().second;
		if (u == y) {
			return d[u];
		}
		q.pop();
		if (st[u])
			continue;
		st[u] = 1;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i][0], w = adj[u][i][1];
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push({d[v], v});
			}
		}
	}
	return -1;
}

i64 bfs(const std::vector<std::vector<std::array<int, 2>>> &adj, int x, int y) {
	std::vector<i64> d(adj.size(), -1);
	std::queue<int> q;
	d[x] = 0;
	q.push(x);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i][0], w = adj[u][i][1];
			if (d[v] == -1) {
				d[v] = d[u] + w;
				if (v == y)
					return d[v];
				q.push(v);
			}
		}
	}
	return -1;
}

void R() {
	int c, n, m, d, q;
	std::cin >> c >> n >> m >> d >> q;
	constexpr int N = 500010;
	static std::array<int, N> w;
	for (int i = 0; i < m; i++)
		std::cin >> w[i];
	std::vector<std::vector<std::array<int, 2>>> adj(m); 
	for (int i = 0; i < n; i++) {
		int k;
		std::cin >> k;
		std::vector<int> a(k), t(k);
		for (int j = 0; j < k; j++) {
			std::cin >> a[j] >> t[j];
			a[j]--;
		}
		for (int j = k - 1; j >= 0; j--) {
			adj.emplace_back();
			int x = adj.size() - 1;
			adj[a[j]].push_back({x, t[j]});
			adj[x].push_back({a[j], t[j]});
			if (j < k - 1) {
				int y = adj.size() - 2;
				adj[x].push_back({y, 0});
			}
		}
	}
	while (q--) {
		int x, y;
		std::cin >> x >> y;
		x--, y--;
		if (c >= 12 && c <= 19)
			std::cout << w[x] + bfs(adj, x, y) + w[y] << "\n";
		else
			std::cout << w[x] + dijkstra(adj, x, y) + w[y] << "\n";
	}
	return;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T = 1;
//	std::cin >> T;
	while (T--)
		R();
	return 0;
}
