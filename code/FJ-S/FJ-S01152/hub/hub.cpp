#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
il int rd(){
	int s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) s = (s << 1) + (s << 3) + ch - 48;
	return s * w;
}
const int N = 200005, M = 105, INF = 1e9;
int cid, T, n, k, mxdep[M << 1][M], sz[N], U[N], V[N], f[M << 1][M][M], mp[M][M], tmp[N], dep[N], fa[N], mxd[M][M][M], E, Ans;
vector <int> e[N];
void dfs(int u, int fa, int E){
	mxdep[E][u] = 0, sz[u] = 1;
	for (int i = 0; i <= n; i++) f[E][u][i] = INF;
	f[E][u][1] = 0;
	for (int v : e[u]) if (v != fa){
		dfs(v, u, E), mxdep[E][u] = max(mxdep[E][u], mxdep[E][v] + 1);
		for (int i = 1; i <= sz[u] + sz[v]; i++) tmp[i] = INF;
		for (int i = 1; i <= sz[u]; i++) for (int j = 0; j <= sz[v]; j++)
			tmp[i + j] = min(tmp[i + j], max(f[E][u][i], f[E][v][j]));
		for (int i = 1; i <= sz[u] + sz[v]; i++) f[E][u][i] = tmp[i];
		sz[u] += sz[v];
	}
	f[E][u][0] = mxdep[E][u] + 1;
}
void dfs(int u){
	dep[u] = dep[fa[u]] + 1;
	for (int v : e[u]) if (v != fa[u]) fa[v] = u, dfs(v);
}
il int lca(int u, int v){
	if (dep[u] < dep[v]) swap(u, v);
	while (dep[u] > dep[v]) u = fa[u];
	while (u != v) u = fa[u], v = fa[v];
	return u;
}
signed Main(){
	n = rd(), k = rd(), Ans = INF;
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) mp[i][j] = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++) mxd[i][j][k] = 0;
	for (int i = 1; i < n; i++) U[i] = rd(), V[i] = rd(), e[U[i]].push_back(V[i]), e[V[i]].push_back(U[i]);
	for (int i = 1; i < n; i++) dfs(U[i], V[i], i), dfs(V[i], U[i], i + n - 1), mp[U[i]][V[i]] = i, mp[V[i]][U[i]] = i + n - 1;
	for (int i = 1; i <= n; i++){
		E = i;
		sort (e[i].begin(), e[i].end(), [](int x, int y){ return mxdep[mp[x][E]][x] > mxdep[mp[y][E]][y]; });
		if (e[i].size() <= 2) continue;
//		cout << i << " " << e[i][0] << " " << e[i][1] << " " << e[i][2] << " Lre\n";
		for (int v : e[i]) for (int w : e[i]) if (v != e[i][0] && w != e[i][0])
			mxd[v][w][i] = mxdep[mp[e[i][0]][i]][e[i][0]] + 1;
		for (int v : e[i]) if (v != e[i][0]) mxd[e[i][0]][v][i] = mxd[v][e[i][0]][i] = mxdep[mp[e[i][1]][i]][e[i][1]] + 1;
		mxd[e[i][0]][e[i][1]][i] = mxd[e[i][1]][e[i][0]][i] = mxdep[mp[e[i][2]][i]][e[i][2]] + 1;
	}
	dfs(1);
	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++){
		int L = lca(i, j), u = fa[i], v = fa[j], ans = 0, lu = i, lv = j, mink = INF;
		while (dep[u] > dep[L]){
			ans = max(ans, mxd[lu][fa[u]][u] + min(dep[i] - dep[u], dep[u] - dep[L] + dep[j] - dep[L]));
			lu = u, u = fa[u];
		}
		while (dep[v] > dep[L]){
			ans = max(ans, mxd[lv][fa[v]][v] + min(dep[j] - dep[v], dep[v] - dep[L] + dep[i] - dep[L]));
			lv = v, v = fa[v];
		}
		if (L != i && L != j){
			if (u == L) u = lu; if (v == L) v = lv;
			ans = max(ans, min(dep[i] - dep[L], dep[j] - dep[L]) + mxd[u][v][L]);
			for (int t = 1; t < k; t++) mink = min(mink, max(f[mp[i][fa[i]]][i][t], f[mp[j][fa[j]]][j][k - t]));
		} else if (L != i){
			if (u == L) u = lu;
			for (int t = 1; t < k; t++) mink = min(mink, max(f[mp[i][fa[i]]][i][t], f[mp[j][u]][j][k - t]));
		} else{
			if (v == L) v = lv;
//			cout << i << " " << j << " " << ans << "\n";
			for (int t = 1; t < k; t++) mink = min(mink, max(f[mp[i][v]][i][t], f[mp[j][fa[j]]][j][k - t]));
		}
		ans = max(ans, mink);
//		cout << i << " " << j << " " << ans << "\n";
		Ans = min(Ans, ans);
	}
//	cout << "\t" << mxdep[mp[6][3]][6] << " Lre\n";
	printf ("%d\n", Ans);
	return 0;
}
signed main(){
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	for (cid = rd(), T = rd(); T--;) Main();
	return 0;
}

