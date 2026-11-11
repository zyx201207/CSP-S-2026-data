#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 1e6 + 10;
vector <int> g[maxn];
int fa[maxn][20], dep[maxn], siz[maxn];
ll dp[maxn];
int n, k;
void dfs(int u, int p) {
	fa[u][0] = p; dep[u] = dep[p] + 1; siz[u] = 1;
	for (int i = 1; i < 20; i++) fa[u][i] = fa[fa[u][i-1]][i-1];
	for (int v : g[u]) {
		if (v == p) continue;
		dfs(v, u);
		siz[u] += siz[v];
	}
}
void dfs2(int u, int p) {
	for (int v : g[u]) if (v != p) {
		dfs2(v, u);
		dp[v] = dp[u] + n - 2 * siz[v];
	}
}
int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 19; i >= 0; i--) if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
int dis(int u, int v) {
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}
int f[maxn];
int Find(int u) {
	return f[u] = (f[u] == u ? u : Find(f[u]));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	srand(time(0));
	int c, T;
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) g[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (n > 20) {
			cout << rand() % (n / __lg(n)) + 1 << "\n";
			continue;
		}
		dep[0] = 0;
		dfs(0, 0);
		int ans = 1e9;
		for (int S = 0; S < (1 << n); S++) {
			if (__builtin_popcount(S) != k) continue;
			for (int i = 0; i < n; i++) f[i] = i;
			for (int i = 0; i < n; i++) if (S & (1 << i)) {
				for (int j : g[i]) if (S & (1 << j)) f[Find(i)] = Find(j);
			}
			int cnt = 0;
			for (int i = 0; i < n; i++) if (S & (1 << i)) cnt += (f[i] == i);
			if (cnt > 2) continue;
			int mx = 0;
			for (int i = 0; i < n; i++) if (!(S & (1 << i))) {
				int mn = 1e9;
				for (int j = 0; j < n; j++) if (S & (1 << j)) mn = min(mn, dis(i, j));
				mx = max(mx, mn);
			}
			ans = min(ans, mx);
		}
		cout << ans << "\n";
	}
	return 0;
}

