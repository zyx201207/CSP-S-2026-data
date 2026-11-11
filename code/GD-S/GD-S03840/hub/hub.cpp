#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;

struct Node {
	int to, nxt;
} e[N << 1];

int used[N];
int dis[110][110];
int n, k;
int h[N], idx;
int vis[N];
int ans = 114514;

inline void add (int u, int v) {
	e[++ idx] = {v, h[u]};
	h[u] = idx;
}

inline void Clear () {
	for (int i = 1; i <= n; i ++) h[i] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) dis[i][j] = 0;
	}
	idx = 0;
	ans = 114514;
}

inline void dfs (int sta, int x, int f) {
	for (int i = h[x]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == f) continue;
		dis[sta][v] = dis[sta][x] + 1;
		dfs (sta, v, x);
	}
}

inline void dfs2 (int u, int f) {
	vis[u] = 1;
	for (int i = h[u];i ; i = e[i].nxt) {
		int v = e[i].to;
		if (v == f || !used[v] || vis[v]) continue;
		dfs2 (v, u);
	}
}

inline void Get () {
	memset (vis, 0, sizeof (vis));
	vector <int> ch;
	for (int i = 1; i <= n; i ++) if (used[i]) ch.push_back (i);
//	for (int i = 0; i < k; i ++) cout << ch[i] << ' ';
//	cout << '\n';
	int ss = 0;
	for (int i = 0; i < k; i ++){
		if (!vis[ch[i]]) {
			ss ++;
			dfs2 (ch[i], 0);
			if (ss > 2) return ;
		}
	}
//	for (int i = 0; i < k; i ++) cout << ch[i] << ' ';
	int maxx = -114514;
	for (int i = 0; i < k; i ++) {
		for (int j = 0; j < k; j ++) {
			if (i == j) continue;
			maxx = max (maxx, dis[ch[i]][ch[j]]);
		}
	}
//	cout << maxx << '\n';
	ans = min (maxx, ans);
}

inline void Fun (int id, int sm) {
	
	if (sm == k) {
		Get ();
		return ;
	}if (id > n) return ;
	used[id] = 1;
	Fun (id + 1, sm + 1);
	used[id] = 0;
	Fun (id + 1, sm);
}

signed main () {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	ios :: sync_with_stdio (false);
//	cin.tie (0);
	int c, t;
	cin >> c >> t;
	while (t --) {
		cin >> n >> k;
		for (int i = 1; i < n; i ++) {
			int u, v;
			cin >> u >> v;
			add (u, v); add (v, u);
		}
		for (int i = 1; i <= n; i ++) dfs (i, i, 0);
//		for (int i = 1; i <= n; i ++) {
//			for (int j = 1; j <= n ;j ++) {
//				cout << dis[i][j] << ' ';
//			}
//			cout << '\n';
//		}
		Fun (1, 0);
		cout << ans << '\n';
		Clear ();
	}
	return 0;
}
