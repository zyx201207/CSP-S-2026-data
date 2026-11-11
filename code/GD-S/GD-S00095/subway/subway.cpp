#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 5e5 + 10;
const int N = 505;
const ll inf = 1e18;
ll c, n, m, D, q;
ll w[M], k[N];
ll d[N][N];
vector <ll> ch[N], t[N]; 
int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m >> D >> q;
	for (int i = 1; i <= m; ++ i) cin >> w[i];
	for (int i = 1; i <= n; ++ i) { 
		cin >> k[i];
		for (int j = 1, a, b; j <= k[i]; ++ j) {
			cin >> a >> b;
			ch[a].push_back (i);
			t[a].push_back (b); 
		}
	}
	for (int i = 1; i <= n; ++ i)
	for (int j = 1; j <= n; ++ j) if (i != j)
		d[i][j] = inf;
	for (int p = 1; p <= m; ++ p) {
		ll len = ch[p].size ();
		if (len <= 1) continue;
		for (int i = 0; i < len; ++ i) 
		for (int j = i + 1; j < len; ++ j) {
			ll u = ch[p][i], v = ch[p][j];
			d[u][v] = min (d[u][v], t[p][i] + t[p][j]);
			d[v][u] = min (d[v][u], t[p][i] + t[p][j]);
		}
	}
	for (int k = 1; k <= n; ++ k) 
	for (int i = 1; i <= n; ++ i)
	for (int j = 1; j <= n; ++ j)
		d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
	while (q --) {
		ll x, y; cin >> x >> y;
		ll res = inf;
		for (int i = 0; i < ch[x].size (); ++ i)
		for (int j = 0; j < ch[y].size (); ++ j) {
			ll u = ch[x][i], v = ch[y][j];
			if (u != v) {
				res = min (res, t[x][i] + t[y][j] + d[u][v]);
			} else {
				res = min (res, t[x][i] + t[y][j]);
			} 
		} 
		cout << res + w[x] + w[y] << '\n';
	}
	return 0;
}
