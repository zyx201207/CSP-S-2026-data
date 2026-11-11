#include <bits/stdc++.h>
#define fst first 
#define scd second
using namespace std;
using ll = long long;
constexpr int N = 500, M = 5e5 + 10;
constexpr ll oo = 1e18;
inline ll rd() {
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + ch - '0'; ch = getchar(); }
	return x * f;
}
ll dis[N][N], w[M];
int c, n, m, d, q;
int sz[N];
vector<pair<int, int>> e[M]; 
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = rd(), n = rd(), m = rd(), d = rd(), q = rd();
	for (int i = 1; i <= m; i++) w[i] = rd();
	for (int i = 1; i <= n; i++) {
		sz[i] = rd();
		for (int j = 1, x, y; j <= sz[i]; j++) {
			x = rd(), y = rd();
			e[x].push_back({i, y});
		}
	} 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)	
			dis[i][j] = oo;
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;
	for (int i = 1; i <= m; i++) 
		for (auto x : e[i]) 
			for (auto y : e[i]) {
				int u = x.fst, v = y.fst;
				dis[u][v] = min(dis[u][v], (ll) x.scd + y.scd);
			}
	for (int k = 1; k <= n; k++) 
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--) {
		int x = rd(), y = rd();
		ll ans = oo;
		for (auto v : e[x]) 
			for (auto w : e[y]) {
				ans = min(ans, dis[v.fst][w.fst] + (ll) v.scd + w.scd);
			}
		cout << ans + w[x] + w[y] << '\n'; 
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
