#include<bits/stdc++.h>
using namespace std;
/*
RE5
*/
#define N 15
int c, t, n, k, ans[N];
bool vis[N], vv[N];
vector<int> g[N];
int bfs(int u) {
	queue<pair<int, int> > q;
	q.push({u, 0});
	for (int i = 1; i <= n; i++) vv[i] = 0;
	while (!q.empty()) {
		pair<int, int> qq = q.front();
		int u = qq.first, w = qq.second;
		q.pop();
		if (vv[u]) continue;
		vv[u] = 1;
		if (vis[u]) return w;
		for (auto v : g[u]) {
			q.push({v, w + 1});
		}
	}
}
void dfs(int u) {
	vis[u] = 0;
	for (auto v : g[u]) {
		if (vis[v]) dfs(v);
	}
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int res = INT_MAX;
		for (int i = 0, cnt, as; i < (1 << n); i++) {
			cnt = 0;
			as = 0;
			for (int j = 1; j <= n; j++) vis[j] = ans[j] = 0;
			for (int j = 1; j <= n; j++) {
				if (i >> (j - 1) & 1) {
					cnt++;
					vis[j] = 1;
				}
			}
			if (cnt != k) continue;
			for (int i = 1; i <= n; i++) {
				as = max(as, bfs(i));
			}
			int kk = 0;
			for (int i = 1; i <= n; i++) {
				if (vis[i]) {
					kk++;
					dfs(i);
				}
			}
			if (kk > 2) continue;
			res = min(res, as);
		}
		cout << res << "\n";
	}
	return 0;
}
