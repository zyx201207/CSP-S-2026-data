#include <bits/stdc++.h>
#define pi pair<int,int>
#define int long long
using namespace std;

const int N = 5003, M = 2.5e6 + 5, inf = 1e9 + 7;

int n, d;
int a[N];
int head[M], to[M], nxt[M], top;

inline void add (int u, int v) {
	nxt[++ top] = head[u];
	to[top] = v;
	head[u] = top;
	return ;
}

priority_queue <pi, vector <pi>, greater <pi> > Q;
int dis[N], vis[N], cnt[N];
inline void dij (int x) {
	for (int i = 1; i <= n; ++ i) dis[i] = inf, vis[i] = 0;
	Q.push ({0, x});
	dis[x] = 0, cnt[x] = 1;
	while (!Q.empty ()) {
		pi x = Q.top ();
		Q.pop ();
		if (vis[x.second]) continue;
		vis[x.second] = 1;
		for (int i = head[x.second]; i; i = nxt[i]) {
			int v = to[i], W = 1;
			if (dis[v] > x.first + W) {
				dis[v] = x.first + W;
				cnt[v] = cnt[x.second];
				Q.push ({dis[v], v});
//				cout << v << ": " << x.second << " " << cnt[v] << "\n";
			} else if (dis[v] == x.first + W) {
				cnt[v] += cnt[x.second];
//				cout << v << ": " << x.second << " " << cnt[v] << "\n"; 
			}
		}
	}
//	for (int i = 1; i <= n; ++ i) cout << dis[i] << " " << cnt[i] << " ";
//	cout << "\n";
	return ;
}

inline void solve () {
	cin >> n >> d;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	memset (head, 0, sizeof head);
	memset (to, 0, sizeof to);
	memset (nxt, 0, sizeof nxt);
	top = 0;
	sort (a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++ i) {
		for (int j = i - 1; j; -- j) {
			if (a[i] - a[j] <= d) {
				add (i, j), add (j, i);
//				cout << i << " " << j << "\n";
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++ i) {
		dij (i);
		for (int j = 1; j <= n; ++ j) {
			if (cnt[j] == 2) ++ ans;
			cnt[j] = 0;
		}
	}
	return void (cout << ans / 2 << "\n");
}

signed main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	int c, t; cin >> c >> t;
	while (t --) solve ();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
5 3
-3 0 2 3 4

1 2 5
1 3 5




*/
