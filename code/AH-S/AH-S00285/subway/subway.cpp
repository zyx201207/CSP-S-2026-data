#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
long long w[M], val[M], vis[M];
long long sum[M], f[M][32], logn[M], deep[M];
vector <long long> g1[N];
vector <long long> g[M];
long long c, n, m, d, q;
void dfs (int u, int fa) {
	f[u][0] = fa;
	deep[u] = deep[fa] + 1;
	sum[u] = sum[fa] + val[u];
	for (int i = 1; i <= logn[deep[u]]; i++) {
		f[u][i] = f[f[u][i - 1]][i - 1];
	} for (auto v : g[u]) {
		if (v == fa) continue;
		dfs (v, u);
	}
} int query (int u, int v) {
	if (deep[u] < deep[v]) swap (u, v);
	while (deep[u] > deep[v]) u = f[u][logn[deep[u] - deep[v]]];
	if (u == v) return u;
	for (int i = logn[deep[u]]; i >= 0; i--) {
		if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
	} return f[u][0];
} int main() {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int K;
		cin >> K;
		while (K --) {
			int x, y;
			cin >> x >> y;
			val[x] += y;
			g1[i].push_back (x);
		}
	} for (int i = 2; i <= m; i++) logn[i] = logn[i / 2] + 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < g1[i].size(); j++) {
			for (int t = j + 1; t < g1[i].size(); t++) {
				if (vis[g1[i][j]] && vis[g1[i][t]]) continue;
				vis[g1[i][j]] = vis[g1[i][t]] = 1;
				g[g1[i][j]].push_back (g1[i][t]);
				g[g1[i][t]].push_back (g1[i][j]);
			}
		}
	} dfs (1, 0);
	while (q --) {
		int x, y;
		cin >> x >> y;
		int lca = query (x, y);
//		cout << sum[x] << ' ' << sum[y] << ' ' << sum[f[lca][0]] << '\n';
		cout << w[x] + w[y] + sum[x] + sum[y] - 2 * sum[lca] << '\n';
	}
	return 0;
} 
