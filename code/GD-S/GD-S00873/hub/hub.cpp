#include <bits/stdc++.h>
using namespace std;
const int N = 5005, INF = 1e9;
vector<int> g[N], leaf; 
int n, k, lca[N][N], dep[N], bcg[N], f[N], ans;
pair<int, int> vis[N];
int find(int x) {
	if (bcg[x] == x) return x;
	return bcg[x] = find(bcg[x]);
}
void clear() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			lca[i][j] = 0;
		}
		dep[i] = 0;
		g[i].clear();
		leaf.clear();
	}
}
void init(int u, int fa) {
	dep[u] = dep[fa] + 1;
	f[u] = fa;
	for (auto v : g[u]) {
		if (v == fa) continue;
		init(v, u);
	}
}
int get_lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	if (lca[u][v]) return lca[u][v];
	if (u == v) return lca[u][v] = lca[v][u] = u;
	return lca[u][v] = lca[v][u] = get_lca(f[u], v);
}
int get(int u, vector<int>& vec) {
	int d = INF;
	for (auto e : vec) {
		d = min(d, dep[u] + dep[e] - 2 * dep[lca[u][e]]);
//		cout << u << ' ' << e
	}
	return d;
}
bool check(vector<int> vec) {
	for (auto e : vec) bcg[e] = e;
	for (auto e : vec) {
		for (auto v : g[e]) {
			if (bcg[v]) bcg[find(v)] = find(e);
		}
	} 	
	int cnt = 0;
	for (auto e : vec) {
		if (bcg[e] == e) cnt++;
		bcg[e] = 0;
	}
	return cnt <= 2;
}
void dfs(int i, vector<int> vec) {
	if (i == n + 1) {
		if (vec.size() != k) return ;
		int res = 0;
		for (int j = 1; j <= n; j++) {
			int ret = get(j, vec);
			if (ret >= ans) {
				res = INF;
				break;
			}
			res = max(ret, res);
		}		
		if (res == INF) return ;
		if (k == 2 || check(vec)) {
			ans = min(ans, res);
		}
		return ;
	}
	if (rand() & 1) {
		dfs(i + 1, vec);
		if (vec.size() < k) {
			vec.push_back(i);
			dfs(i + 1, vec);
			vec.pop_back();
		}
	} else {	
		if (vec.size() < k) {
			vec.push_back(i);
			dfs(i + 1, vec);
			vec.pop_back();
		}
		dfs(i + 1, vec);
	}
}
void solve() {	
	cin >> n >> k;
	clear();
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n == 1) {
		cout << 0 << '\n';
		return ;
	}
	if (n == 2) {
		if (k == 1) cout << 1 << '\n';
		else cout << 0 << '\n';
		return ;
	}
	init(1, 0);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (lca[i][j] == 0) get_lca(i, j); 
	ans = INF;
	dfs(1, vector<int> ());
	cout << ans << '\n';
	clear();
}
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) solve();
	return 0;
} 
