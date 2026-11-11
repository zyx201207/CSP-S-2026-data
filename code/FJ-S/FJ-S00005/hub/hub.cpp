#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int c, t, n, k, u, v, fa[N], dep[N], f[N][25], ok[25][25];
vector<int> g[N];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void dfs(int u, int pre) {
	dep[u] = dep[pre] + 1, f[u][0] = pre;
	for (int i = 1; i <= 20; i++) f[u][i] = f[f[u][i - 1]][i - 1];
	for (int v : g[u]) if (v != pre) dfs(v, u); 
}
int lca(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	int tmp = dep[v] - dep[u];
	for (int i = 0; tmp; i++, tmp >>= 1)
		if (tmp & 1) v = f[v][i];
	if (u == v) return u;
	for (int i = 20; i >= 0 && u != v; i--)
		if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
	return f[u][0];
}
int dis(int u, int v) {
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d %d", &c, &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) {
			g[i].clear(), dep[i] = 0;
			for (int j = 1; j <= n; j++) ok[i][j] = 0;
			for (int j = 0; j <= 20; j++) f[i][j] = 0;
		}
		for (int i = 1; i < n; i++)
			scanf("%d %d", &u, &v),
			g[u].push_back(v),
			g[v].push_back(u), ok[u][v] = ok[v][u] = 1;
		if (n > 10) {
			printf("0\n");
			continue;
		} 
		dfs(1, 0);
		int ans = 2e9;
		for (int mask = 0; mask < (1 << n); mask++) {
			if (__builtin_popcount(mask) != k)
				continue;
			vector<int> idx, vis(n + 1, 0), d(n + 1, 0);
			for (int i = 1; i <= n; i++) {
				fa[i] = i;
				if (mask & (1 << (i - 1))) 
					idx.push_back(i), vis[i] = 1;
			}
			for (int i : idx)
				for (int j : idx)
					if (i != j && ok[i][j]) fa[find(i)] = find(j);
			unordered_set<int> st;
			for (int i : idx) st.insert(find(i));
			if ((int)st.size() > 2) continue;
			int mx = 0;
			for (int i = 1; i <= n; i++) 
				if (!vis[i]) {
					int mn = 2e9;
					for (int j : idx) mn = min(mn, dis(i, j)); 
					d[i] = mn;
				}
			for (int i = 1; i <= n; i++) mx = max(mx, d[i]);
			ans = min(ans, mx);
		}
		printf("%d\n", ans);
	}
  return 0;
}
