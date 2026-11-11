#include<bits/stdc++.h>
using namespace std;
#define int long long
int fa[20];
int find(int x)
{
	if (fa[x] == x) {
		return x;
	}
	return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
	fa[find(x)] = find(y);
}
bool same(int x, int y)
{
	return find(x) == find(y);
}
void init()
{
	for (int i = 1; i <= 19; i++) {
		fa[i] = i;
	}
}
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> edges(n + 1);
	vector<pair<int, int>> edge;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
		edge.push_back({u, v});
	}
	int ans = 1e9;
	for (int i = 0; i < (1 << n); i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				cnt++;
			}
		}
		if (cnt != k) {
			continue;
		}
		vector<bool> vis(n + 1, 0);
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				vis[j + 1] = 1;
			}
		}
		init();
		for (int j = 0; j < n - 1; j++) {
			if (vis[edge[j].first] && vis[edge[j].second]) {
				merge(edge[j].first, edge[j].second);
			}
		}
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (vis[j] && find(j) == j) {
				cnt++;
			}
		}
		if (cnt > 2) {
			continue;
		}
		vector<int> dist(n + 1, INT_MAX);
		queue<int> q;
		for (int j = 1; j <= n; j++) {
			if (vis[j]) {
				dist[j] = 0;
				q.push(j);
			}
		}
		int tp = 0;
		while (q.size()) {
			int u = q.front();
			q.pop();
			for (auto nex : edges[u]) {
				if (dist[nex] == INT_MAX) {
					dist[nex] = dist[u] + 1;
					q.push(nex);
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			tp = max(tp, dist[j]);
		}
		ans = min(ans, tp);
	}
	cout << ans << '\n';
}
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--) {
		solve();
	}
	return 0;
}