#include <bits/stdc++.h>
#define int long long
#define N (int)(1e3 + 5)
#define INF (long long)1e18
using namespace std;
int n, k, bit[N], vis[N], ans;
vector <int> a[N];
inline void Tree (int x, int fa) {
	if (vis[x] == 1 || bit[x] == 0)
		return ;
	vis[x] = 1;
	for (int i = 0; i < a[x].size (); i ++)
		if (a[x][i] != fa)
			Tree (a[x][i], x);
}
inline int DFS (int x, int fa) {
	if (bit[x] == 1)
		return 0;
	int c = INF;
	for (int i = 0; i < a[x].size (); i ++)
		if (a[x][i] != fa)
			c = min (c, DFS (a[x][i], x));
	return c + 1;
}
inline int Find (int x) {
	return DFS (x, 0);
}
inline void Dfs (int x) {
	if (x == n + 1) {
		int K = 0;
		for (int i = 1; i <= n; i ++)
			K += bit[i];
		if (K != k)
			return;
		int cnt = 0;
		for (int i = 1; i <= n; i ++)
			vis[i] = 0;
		for (int i = 1; i <= n; i ++)
			if (bit[i] == 1 && vis[i] == 0) {
				cnt ++;
				Tree (i, 0);
			}
		//cout << cnt << '\n';
		if (cnt > 2)
			return ;
		int maxx = 0;
		for (int i = 1; i <= n; i ++) {
			//cout << Find (i) << '\n';
			maxx = max (maxx, Find (i));
		}
		ans = min (ans, maxx);
		return ;
	}
	bit[x] = 1;
	Dfs (x + 1);
	bit[x] = 0;
	Dfs (x + 1);
}
inline void solve () {
	ans = INF;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		a[i].clear ();
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back (v), a[v].push_back (u);
	}
	Dfs (1);
	cout << ans << '\n';
}
signed main () {
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	int C, T;
	cin >> C >> T;
	while (T --)
		solve ();
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
