#include <bits/stdc++.h>
using namespace std;

namespace Creeper{
	const int N = 15;
	int c, n, k, cnt, p[N], dis[N][N], ans = 1e9;
	bool vis[N];
	vector<int> G[N];
	void get(int rt, int u, int fa) {
		for (auto v: G[u]) {
			if (v == fa) continue;
			dis[rt][v] = dis[rt][u] + 1;
			get(rt, v, u);
		}
	}
	void dfss(int u) {
		vis[u] = 1;
		for (auto v: G[u]) {
			if (vis[v] || !p[v]) continue;
			dfss(v);
		}
	}
	void dfs(int u, int m) {
		if (u > n) {
			if (m) return;
			int sum = 0, cnt = 0;
			for (int i = 1; i <= n; i++) vis[i] = 0;
			for (int i = 1; i <= n; i++) {
				if (!p[i] || vis[i]) continue;
				dfss(i);
				cnt++;
			}
			if (cnt > 2) return;
			for (int i = 1; i <= n; i++) {
				if (p[i]) continue;
				int res = 1e9;
				for (int j = 1; j <= n; j++) {
					if (p[j]) {
						res = min(res, dis[i][j]);
					}
				}
				sum = max(sum, res);
			}
			ans = min(ans, sum);			
			return;
		}
		if (m) {
			p[u] = 1;
			dfs(u + 1, m - 1);
			p[u] = 0;
		}
		dfs(u + 1, m);
	}
	void solve() {
		cin >> n >> k;
		ans = 1e9;
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		} 
		for (int i = 1; i <= n; i++) {
			get(i, i, 0);
		}
		dfs(1, k);
		cout << ans << '\n';
	}
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> Creeper::c >> T;
	while (T--) Creeper::solve();
}
