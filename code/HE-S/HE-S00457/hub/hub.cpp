#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, k, fa[N][21], dep[N], b[N]; bool use[N];
vector < int > G[N]; int ans;

void dfs1(int u, int father) {
	fa[u][0] = father; dep[u] = dep[father] + 1;
	for (int i = 1; i <= 20; i ++) 
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto v : G[u]) {
		if (v == father) continue ;
		dfs1(v, u); 
	}
}

int getlca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i --) 
		if (dep[x] - (1 << i) >= dep[y]) 
			x = fa[x][0];
	if (x == y) return x;
	for (int i = 20; i >= 0; i --) 
		if (fa[x][i] != fa[y][i]) {
			x = fa[x][i];
			y = fa[y][i];
		}
	return fa[x][0];
}

int getdis(int x, int y) {
	int LCA = getlca(x, y);
	return dep[x] + dep[y] - 2 * dep[LCA];
}

void solve(int step) {
	if (step > k) {
		vector < bool > vis(n + 1, 0);
		for (int i = 1; i <= k; i ++) vis[b[i]] = 1;
		int cnt = 0;
		for (int i = 1; i <= k; i ++) {
			int u = b[i]; bool flag = 0;
			for (auto v : G[u]) {
				if (vis[v]) {
					flag = 1;
					break ;
				}
			}
			if (!flag) cnt ++;
		}
		if (cnt > 2) return ;
		int res = 0;
		for (int i = 1; i <= n; i ++) {
			if (vis[i]) {
				res = max(res, 0);
				continue ;
			}
			int now = 1e9;
			for (int j = 1; j <= k; j ++) {
				int d = getdis(i, b[j]);
				now = min(now, d);
			}
			res = max(res, now);
		} 
		if (res == 0) {
		}
		ans = min(ans, res);
		return ;
	} 
	for (int i = 1; i <= n; i ++) {
		if (use[i]) continue ;
		b[step] = i; use[i] = 1;
		solve(step + 1);
		use[i] = 0; b[step] = 0;
	}
}

void work() {
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) G[i].clear();
	for (int i = 1; i < n; i ++) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1, 0);
	ans = 1e9; solve(1);
	cout << ans << "\n";
} 

int main() {
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int c, t; cin >> c >> t;
	while (t --) work();
	
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
