/*
17:07 15pts到手 
18:10 滚木 
*/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 2e5 + 5;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
int test = 1, tt = 1;
int C;
int n, k;
vector<vector<int>> e;
vector<bool> vis;
vector<int> s;//并查集 

int find(int x) {
	if (x == s[x]) return x;
	return s[x] = find(s[x]);
}

void floyd(vector<vector<int>> &dis) {
	for (int k = 1; k <= n; k++) {
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= n; v++) {
				dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
			}
		}
	}
}

void solve_1_to_3() {
	cin >> n >> k;
	e.assign(n + 2, vector<int>());
	vis.resize(n + 2, false);
	s.resize(n + 2);
	vector<vector<int>> dis(n + 2, vector<int>(n + 2, inf));
	for (int i = 2, u, v; i <= n; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
		dis[u][v] = dis[v][u] = 1;
	}
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
	}
	floyd(dis);
	int ans = inf;
	for (int mask = 0; mask < (1 << n); mask++) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (mask >> i - 1 & 1) vis[i] = true;
			else vis[i] = false;
			cnt += vis[i];
		}
		if (cnt != k) continue;
		for (int i = 1; i <= n; i++) {
			s[i] = i;
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) continue;
			for (auto v : e[i]) {
				if (vis[v]) {
					s[find(v)] = find(i);
				}
			}
		}
		set<int> st;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) continue;
			st.insert(find(i));
		}
		if (st.size() > 2) continue;
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			int dist = inf;
			for (int j = 1; j <= n; j++) {
				if (!vis[j]) continue;
				dist = min(dist, dis[i][j]);
			}
			res = max(res, dist);
		}
		ans = min(ans, res);
	}
	cout << ans << '\n';
}
vector<int> dep, fa, siz, son, top;

void dfs1(int u, int f) {
	fa[u] = f;
	dep[u] = dep[f] + 1;
	siz[u] = 1;
	for (auto v : e[u]) {
		if (v == f) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) {
			son[u] = v;
		}
	}
}

void dfs2(int u, int topx) {
	top[u] = topx;
	if (!son[u]) return;
	dfs2(son[u], topx);
	for (auto v : e[u]) {
		if (v == son[u] || v == fa[u]) continue;
		dfs2(v, v);
	}
}

int lca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		u = fa[top[u]];
	}
	if (dep[u] > dep[v]) swap(u, v);
	return u;
}

void solve_7() {
	cin >> n >> k;
	e.assign(n + 2, vector<int>());
	dep.resize(n + 2, 0);
	fa.resize(n + 2, 0);
	siz.resize(n + 2, 0);
	son.resize(n + 2, 0);
	top.resize(n + 2, 0);
	vector<vector<int>> dis(n + 2, vector<int>(n + 2, inf));
	for (int i = 2, u, v; i <= n; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = dis[j][i] = (dep[i] + dep[j] - dep[lca(i, j)] * 2);
		}
	} 
//	for (int i = 1; i <= n; i++) {
//		cout <<top[i] << ' ';
//	}
//	cout << '\n';
	//选两个点
	int ans = inf;
	for (int u = 1; u < n; u++) {
		for (int v = u + 1; v <= n; v++) {
			int res = -inf;
			for (int i = 1; i <= n; i++) {
				if (i == u || i == v) continue;
				res = max(res, min(dis[i][u], dis[i][v]));
			}
			ans = min(ans, res);
		}
	} 
	cout << ans << '\n';
}

void solve_13_to_14() {
	cin >> n >> k;
	e.assign(n + 2, vector<int>());
	for (int i = 2, u, v; i <= n; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cout << n / (k + 1) << '\n';
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> C;
	cin >> test;
	for (; tt <= test; tt++) {
		if (C == 7) {
			solve_7();
			continue;
		} 
		if (C == 13 || C == 14) {
			solve_13_to_14();
			continue;
		}
		solve_1_to_3();
	}
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
