#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 15;
int n, k, dis[N][N], d[N];
bool b[N], vis[N];
vector<int> G[N];

void dfs(int u, int fa) {
	vis[u] = true;
	for (int v : G[u]) {
		if (v == fa || !b[v]) continue;
		dfs(v, u);
	}
}

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		G[i].clear();
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		dis[u][v] = 1;
		dis[v][u] = 1;
	}
	floyd();
	int ans = 2e9;
	for (int i = 0; i < (1 << n); i++) {
		memset(b, false, sizeof b);
		memset(vis, false, sizeof vis);
		vector<int> v;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				b[j + 1] = true;
				v.emplace_back(j + 1);
			}
		}
		if (v.size() != k) continue;
		int cnt = 0;
		for (int u : v) {
			if (!b[u]) continue;
			if (!vis[u]) {
				++cnt;
				dfs(u, -1);
			}
		}
		if (cnt > 2) continue;
		int x = 0;
		for (int i = 1; i <= n; i++) {
			if (b[i]) continue;
			int d = 2e9;
			for (int j : v) {
				d = min(d, dis[i][j]);
			}
			x = max(x, d);
		}
		ans = min(ans, x);
	}
	cout << ans << '\n';
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}
