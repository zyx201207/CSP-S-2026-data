#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pii;

#define file(a) freopen(#a ".in", "r", stdin), freopen(#a ".out", "w", stdout)

const int M = 5e5 + 5, N = 505;
int c, n, m, d, q, wgt[M]; ll f[N][N];
vector<pii> vec[M];

int main() {
	file(subway);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> wgt[i];
	for(int i = 1, k; i <= n; i++) {
		cin >> k;
		for(int j = 1, x, y; j <= k; j++) cin >> x >> y, vec[x].eb(i, y);
	} for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) f[i][j] = i != j ? 1e15 : 0;
	for(int i = 1; i <= m; i++) {
		int t = (int)vec[i].size();
		assert(t <= d);
		for(int j = 0; j < t; j++) for(int k = j + 1; k < t; k++) {
			auto [u, wu] = vec[i][j];
			auto [v, wv] = vec[i][k];
			f[u][v] = min(f[u][v], (ll)wu + wv);
			f[v][u] = min(f[v][u], (ll)wu + wv);
		}
	} for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	for(int i = 1, u, v; i <= q; i++) {
		cin >> u >> v;
		ll res = 2e18;
		for(auto [tu, wu] : vec[u]) for(auto [tv, wv] : vec[v]) res = min(res, wu + f[tu][tv] + wv);
		cout << wgt[u] + res + wgt[v] << '\n';
	} cout << flush;
	return 0;
} /*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
