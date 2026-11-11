#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 1e6 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct Node {
	int u;
	ll d;
	bool operator > (const Node &o) const { return d > o.d; }
};
int w[maxn];
vector <Node> g[510], e[maxn];
ll dis[510][510], d[510];
bool vis[510];
void dijkstra(int s) {
	memset(d, 0x3f, sizeof(d));
	memset(vis, false, sizeof(vis));
	priority_queue <Node, vector<Node>, greater<Node> > q;
	d[s] = 0; q.push({s, d[s]});
	while (!q.empty()) {
		int u = q.top().u; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto p : g[u]) {
			int v = p.u, w = p.d;
			if (d[u] + w < d[v]) {
				d[v] = d[u] + w;
				q.push({v, d[v]});
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, dd, q;
	cin >> c >> n >> m >> dd >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			e[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= m; i++) {
		for (auto e1 : e[i]) {
			for (auto e2 : e[i]) if (e1.u != e2.u) {
				g[e1.u].push_back({e2.u, e1.d + e2.d});
				g[e2.u].push_back({e1.u, e1.d + e2.d});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		for (int j = 1; j <= n; j++) dis[i][j] = d[j];
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		ll ans = 1e18;
		for (auto e1 : e[u]) {
			for (auto e2 : e[v]) {
				ans = min(ans, dis[e1.u][e2.u] + e1.d + e2.d);
			} 
		}
		cout << ans + w[u] + w[v] << "\n";
	}
	return 0;
}

