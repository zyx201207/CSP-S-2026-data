#include <bits/stdc++.h>
#define int long long
#define fin(x) freopen(#x ".in", "r", stdin);
#define fout(x) freopen(#x ".out", "w", stdout);
#define file(x) fin(x);fout(x);
using namespace std;
constexpr int N = 5e2 + 5;
constexpr int M = 5e5 + 5;
constexpr int inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, a[M], dis[N][N];
vector <pair <int, int> > e[M];
signed main() {
	file(subway);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q, memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; ++i) dis[i][i] = 0;
	for (int i = 1; i <= m; ++i) cin >> a[i];
	for (int i = 1, x, y, z; i <= n; ++i) {
		cin >> x;
		while(x--) cin >> y >> z, e[y].emplace_back(i, z);
	}
	for (int i = 1; i <= m; ++i) for (auto j : e[i]) for (auto k : e[i])
		dis[j.first][k.first] = min(dis[j.first][k.first], j.second + k.second);
	for (int k = 1; k <= n; ++k) for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j)
		dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1, x, y; i <= q; ++i) {
		cin >> x >> y;
		int ans = inf;
		for (auto j : e[x]) for (auto k : e[y]) ans = min(ans, dis[j.first][k.first] + j.second + k.second);
		cout << ans + a[x] + a[y] << '\n'; 
	}
}

