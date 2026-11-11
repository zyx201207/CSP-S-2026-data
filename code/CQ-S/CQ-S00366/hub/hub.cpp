#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int C, T, n, m;

int head[N], cnt, g[N], rt;
struct Edge { int to, next; } e[N << 1];
inline void AddEdge (int u, int v) {
	e[++cnt] = {v, head[u]};
	head[u] = cnt;
}

int dep[N], mx[N], fa[N], dis[105][105], ans;
//int f[1005][1005][3];
inline void dfs (int u, int Fa) {
	dep[u] = dep[Fa] + 1; mx[u] = dep[u]; fa[u] = Fa;
	for (int i = head[u]; i; i = e[i].next) {
		if (e[i].to == Fa) continue;
		dfs (e[i].to, u);
		mx[u] = max (mx[u], mx[e[i].to]);
	}
//	for (int op = 1; op <= 2; ++op) {
//		for (int j = 0; j <= n; ++j) {
//			
//		}
//	}
}

inline void get (int u, int Fa, int U, int sum) {
	dis[U][u] = sum;
	for(int i = head[u]; i; i = e[i].next) {
		if (e[i].to == Fa) continue;
		get (e[i].to, u, U, sum + 1);
	}
}

int _[10], f[N];
inline int find (int x) {
	return (f[x] == x) ? x : (f[x] = find (f[x]));
}

inline void dfs2 (int x, int res) {
	if (res > m) return ;
	if (x > n) {
		for (int i = 1; i <= n; ++i) f[i] = i;
		for (int i = 1; i <= n; ++i) {
			if (_[i] == 0) continue;
			for (int j = head[i]; j; j = e[j].next) {
				if (_[e[j].to] == 0) continue;
				f[find (i)] = find (e[j].to);
			}
		}
		int op = 0;
		for (int i = 1; i <= n; ++i)
			if (find (i) == i && _[i] == 1) op++;
		if (op > 2) return ;
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			if (_[i] == 1) continue;
			int num = n + 1;
			for (int j = 1; j <= n; ++j) {
				if (_[j] == 0) continue;
				num = min (num, dis[i][j]);
			}
			sum = max (sum, num);
		}
		ans = min (ans, sum);
		return ;
	}
	_[x] = 1;
	dfs2 (x + 1, res + 1);
	_[x] = 0;
	dfs2 (x + 1, res);
}

inline void solve () {
	cin >> n >> m; cnt = 0; rt = 1; ans = n + 1;
	for (int i = 1; i <= n; ++i) head[i] = g[i] = 0;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		AddEdge (u, v);
		AddEdge (v, u);
		g[u]++; g[v]++;
	}
	if (m == n) { cout << "0\n"; return ; }
	for (int i = 1; i <= n; ++i) get (i, 0, i, 0);
	dfs2 (1, 0);
	cout << ans << '\n';
	
//	for(int i = 1; i <= n; ++i)
//		if (g[i] == 1) rt = i;
//	dfs (rt, 0);
//	int k = n / 2;
//	int len = k + 2;
	
}

signed main () {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> C >> T;
	while (T--) solve ();
	
	return 0;
}
