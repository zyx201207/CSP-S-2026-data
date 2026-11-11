#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
typedef pair<int, int> pii;
int c, n, m, d, q;
int dist[500050];
int w[500050];
struct edge {
	int to;
	int w;
};
vector<edge> adj[500050];
void dijkstra(int src) {
	fill(dist + 1, dist + m + 1, INF);
	dist[src] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, src});
	while (!pq.empty()) {
		pii tope = pq.top();
		pq.pop();
		int d = tope.first;
		int u = tope.second;
		if (d > dist[u]) continue;
		for (size_t i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].to;
			int w = adj[u][i].w;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c;
	if (c == 0) c = 1;
	while (c--) {
		cin >> n >> m >> d >> q;
		for (int i = 1; i <= m; ++i) {
			cin >> w[i];
			adj[i].clear();
		}
		int k;
		for (int i = 1; i <= n; ++i) {
			cin >> k;
			int memory[3] = {};
			int first[3] = {};
			for (int j = 1; j <= k; ++j) {
				int u, v;
				cin >> u >> v;
				if (j != 1) {
					adj[memory[1]].push_back({u, memory[2] + v});
					adj[u].push_back({memory[1], memory[2] + v});
				}
				if (j == 1) {
					first[1] = u;
					first[2] = v;
				}
				memory[1] = u, memory[2] = v;
				if (j == k) {
					adj[u].push_back({first[1], first[2] + v});
					adj[first[1]].push_back({u, first[2] + v});
				}
			}
		}
		for (int i = 1; i <= q; ++i) {
			int x, y;
			cin >> x >> y;
			dijkstra(x);
			for (int j = 1; j <= m; ++j) {
				cout << dist[j] << ' ';
			}
			cout << endl;
			cout << w[x] + dist[y] + w[y] << endl;
		}
	}
	return 0;
}
