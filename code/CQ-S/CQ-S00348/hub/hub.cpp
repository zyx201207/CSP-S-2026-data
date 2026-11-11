#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int n, k;
vector <int> e[N];
int vis[N], viss[N], p[N];

inline void dfs1 (int x) {
	vis[x] = 1;
	for (auto v : e[x]) {
		if (vis[v] || !p[v]) continue;
		dfs1 (v);
	}
	return ;
}

int ret1, ret2, ans;
inline void dfs2 (int x, int dist) {
	if (p[x]) return void (ret1 = min (ret1, dist));
	viss[x] = 1;
	for (auto v : e[x]) {
		if (viss[v]) continue;
		dfs2 (v, dist + 1);
	}
	viss[x] = 0;
	return ;
}

inline void dfs (int x, int cnt1) {
	if (cnt1 > k) return ;
	if (x > n) {
		int cnt = 0;
		for (int i = 1; i <= n; ++ i) vis[i] = 0;
		for (int i = 1; i <= n; ++ i) {
			if (!vis[i] && p[i]) {
				dfs1 (i);
				++ cnt;
			}
		}
		if (cnt > 2) return ;
		ret2 = 0;
		for (int i = 1; i <= n; ++ i) {
			ret1 = n + 1;
			dfs2 (i, 0);
			ret2 = max (ret2, ret1);
		}
//		for (int i = 1; i <= n; ++ i) cout << p[i] << " ";
//		cout << ret2 << "\n";
		return void (ans = min (ans, ret2));
	}
	p[x] = 0, dfs (x + 1, cnt1);
	p[x] = 1, dfs (x + 1, cnt1 + 1), p[x] = 0;
	return ;
}

inline void solve () {
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) e[i].clear ();
	for (int i = 1, u, v; i < n; ++ i) {
		cin >> u >> v;
		e[u].push_back (v), e[v].push_back (u);
	}
	ans = n + 1;
	dfs (1, 0);
	cout << ans << "\n";
	return ;
}

signed main () {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	int c, t; cin >> c >> t;
	while (t --) solve ();
	return 0;
}

