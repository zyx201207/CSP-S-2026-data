#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, k, fa[N][35], dep[N], vis[N];
vector<int> g[N];
int f[N];
int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}
void dfs(int u, int pa) {
	dep[u] = dep[pa] + 1;
	fa[u][0] = pa;
	for (int i = 1; i <= 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int v : g[u]) {
		if (v != pa) dfs(v, u);
	}
}
int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 20; i >= 0; i--) {
		if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	}
	if (u == v) return u;
	for (int i = 20; i >= 0; i--) {
		if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	}
	return fa[u][0];
}
int dist(int u, int v)  {
	return dep[u] + dep[v] - dep[lca(u, v)] * 2;
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, T;
	cin >> c >> T;
	while (T--) {

		int n, k;
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 0);
		
		int ans = 0x3f3f3f3f;
		for (int m = 0; m < 1 << n; m++) {
		for (int i = 1; i <= n; i++) f[i] = i;
			memset(vis, 0, sizeof vis);
			int cnt = 0;
			for (int i = 0; i < n; i++) if ((m >> i) & 1) cnt++, vis[i + 1] = true;
			if (cnt == k) {
				for (int i = 1; i <= n; i++) {
					if (!vis[i]) continue;
					for (int v : g[i]) {
						if (vis[v]) {
							if (find(i) != find(v)) f[find(i)] = find(v);
						//	cout << "!!!";
						}
					}
				}
				set<int> se;
				for (int i = 1; i <= n; i++) if (vis[i]) se.insert(find(i));
			//	if (vis[2] && vis[3] && vis[9]) {
				//	cout << f[2] << " " << f[3] << " " << f[9];
				//	for (int v : se) cout << v << " ";
			//		cout << '\n';
			//	}
				if (se.size() <= 2) {
					int mx = 0;
					for (int i = 1; i <= n; i++) {
						int mi = 0x3f3f3f3f;
						for (int j = 1; j <= n; j++) {
							if (vis[j]) {
								mi = min(mi, dist(i, j));
							//	cout << i << " " << j << " " << dist(i, j) << '\n';
							}
						}
						mx = max(mx, mi);
					}
					ans = min(ans, mx);
//					if (mx == 1) {
//						for (int i = 1; i <= n; i++) cout << vis[i] << " ";
//						cout << '\n';
//					}
				}
				
			}
		}
		cout << ans << '\n';
		for (int i = 1; i <= n; i++) g[i].clear();
	}
	return 0;
}

/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
