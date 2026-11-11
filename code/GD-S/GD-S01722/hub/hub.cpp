#include<bits/stdc++.h>
using namespace std;
const int N = 3007;
int dep[N], fa[N], top[N], son[N], siz[N], D[N];
vector<int> g[N];
void dfs1(int u, int f) {
	dep[u] = dep[f] + 1, siz[u] = 1, fa[u] = f;
	for (int v : g[u]) {
		if (v == f) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) son[u] = v;
	}
}
void dfs2(int u, int t) {
	top[u] = t;
	if (son[u]) dfs2(son[u], t);
	for (int v : g[u]) if (v != fa[u] && v != son[u]) dfs2(v, v);
}
int LCA(int x, int y) {
	while(top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	return x;
}
int get(int x, int y) { return dep[x] + dep[y] - 2*dep[LCA(x, y)]; }
int lowbit(int x) { return x & -x; }
int popcount(int x) {
	int res = 0;
	for (; x; x -= lowbit(x)) res++;
	return res;
}
bool vis[N], used[N];
void dfs(int u, int f) {
	vis[u] = 1;
	for (int v : g[u]) {
		if (v == f || used[v] == 0) continue;
		dfs(v, u);
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t; cin >> c >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		for (int i = 1; i <= n; ++i) g[i].clear(), dep[i] = 0, fa[i] = 0, top[i] = 0, son[i] = 0, siz[i] = 0;
		for (int i = 1; i < n; ++i) {
			int u, v; cin >> u >> v;
			g[u].push_back(v), g[v].push_back(u);
		}
		dfs1(1, 0); dfs2(1, 1);
		int ans = 1e9 + 7;
		for (int s = 0; s < (1 << n); ++s) {
			if (popcount(s) != k) continue;
			int tot = 0, dis = 0;
			for (int i = 1; i <= n; ++i) vis[i] = 0, used[i] = 0, D[i] = 1e9 + 7;
			for (int i = 1; i <= n; ++i) {
				if ((s >> (i-1)) & 1) used[i] = 1;
			}
			int cnt = 0;
			for (int i = 1; i <= n; ++i) if (used[i] == 1 && vis[i] == 0) dfs(i, 0), cnt++;
			if (cnt > 2) continue;
			for (int i = 1; i <= n; ++i) {
				if (used[i] == 1) D[i] = 0;
				for (int j = 1; j <= n; ++j) {
					if (used[j] == 1) D[i] = min(D[i], get(i, j)); 
				}
			}
			for (int i = 1; i <= n; ++i) dis = max(dis, D[i]);
			ans = min(ans, dis);
		}
		cout << ans << "\n";
	}
	return 0;
}

