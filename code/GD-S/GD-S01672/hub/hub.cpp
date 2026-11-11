#include <bits/stdc++.h>
#define int long long
using namespace std; 
const int maxn = 1e5 + 5;
int n, k, vis[maxn], col[maxn], dep[maxn], f[maxn][20];
vector <int> G[maxn];
void dfs(int u, int c) {
	col[u] = c;
	for (int v : G[u]) 
		if (vis[v] && !col[v]) 
			dfs(v, c);
	return;
}
void dfs2(int u, int fa) {
	dep[u] = dep[fa] + 1, f[u][0] = fa;
	for (int i = 1; i < 20; i++) f[u][i] = f[f[u][i - 1]][i - 1];
	for (int v : G[u]) if (v != fa) dfs2(v, u);
}
int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 19; i >= 0; i--) if (dep[f[u][i]] >= dep[v]) u = f[u][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--) if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
	return f[u][0];
}
inline int get(int u, int v) { return dep[u] + dep[v] - (dep[lca(u, v)] << 1); }
int calc(int s, int cnt = 0) {
	vector <int> node1, node2;
	for (int i = 1; i <= n; i++)
		if (s & (1 << (i - 1))) node1.push_back(i), vis[i] = true;
		else node2.push_back(i), vis[i] = false;
	for (int i = 1; i <= n; i++) col[i] = 0;
	for (int i = 1; i <= n; i++) if (vis[i] && !col[i]) dfs(i, ++cnt);
	if (cnt > 2) return 1e18;
	int ret = -1e18;
	for (int i : node2) {
		int minn = 1e18;
		for (int j : node1) minn = min(minn, get(i, j));
		ret = max(ret, minn);
	}
	return ret;
}
inline void add_edge(int u, int v) {
	G[u].push_back(v), G[v].push_back(u);
}
void solve(int ans = 1e18) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) G[i].clear();
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, add_edge(u, v);
	dfs2(1, 0);
	for (int s = 0; s < (1 << n); s++) {
		if (__builtin_popcount(s) != k) continue;
		ans = min(ans, calc(s));
	}
	return cout << ans << '\n', void();
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0),
	cin.tie(0), cout.tie(0);
	int C, T; cin >> C >> T;
	while (T--) solve();
	return 0;
}
/*
人活着就是为了黑部奈叶香
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
