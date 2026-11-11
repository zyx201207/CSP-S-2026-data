#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5010;
int c, T;
int n, k;
vector <int> G[MAXN];
int dfn[MAXN], top[MAXN], siz[MAXN], dep[MAXN], son[MAXN], fa[MAXN], tot;
int ans = 1e18;
bool vis[MAXN];
int s[MAXN];
int anc[MAXN][MAXN];
bool viss[MAXN];
void dfs1(int u, int f) {
	dep[u] = dep[f] + 1;
	siz[u] = 1;
	fa[u] = f;
	for (auto v : G[u]) {
		if (v == f) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) son[u] = v;
	}
}
void dfs2(int u, int Top) {
	top[u] = Top;
	dfn[u] = ++tot;
	if (son[u]) dfs2(son[u], Top);
	for (auto v : G[u]) {
		if (v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}
int LCA(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}
int dist(int x, int y) {
	return dep[x] + dep[y] - 2 * dep[anc[x][y]];
}
void Dfs(int u) {
	viss[u] = 1;
	for (auto v : G[u]) {
		if (viss[v] || !vis[v]) continue;
		Dfs(v);
	}
}
int calc() {
	int mx = 0;
	for (int i = 1; i <= n; i++) viss[i] = 0;
	int ltk = 0;
	for (int i = 1; i <= k; i++) {
		if (!viss[s[i]]) {
			ltk++;
			Dfs(s[i]);
		}
	}
	if (ltk > 2) {
//		cout << "banana\n";
		return 1e18;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			int res = 1e18;
			for (int j = 1; j <= k; j++) res = min(res, dist(i, s[j]));
			mx = max(mx, res);
		}
	}
	return mx;
}
void dfs(int x) {
	if (x > k) {
		ans = min(ans, calc());
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			s[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}
void solve() {
	cin >> n >> k;
	tot = 0;
	ans = 1e18;
	for (int i = 1; i <= n; i++) G[i].clear(), dfn[i] = top[i] = dep[i] = fa[i] = son[i] = siz[i] = 0;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) anc[i][j] = LCA(i, j);
	dfs(1);
	cout << ans << '\n';
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) solve();
	return 0;
}
