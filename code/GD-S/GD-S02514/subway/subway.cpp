#include<bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = (l) ; i <= (r) ; i ++)
#define per(i, l, r) for (int i = (r) ; i >= (l) ; i --)

using ll = long long;

const int N = 5e2 + 10;
const int M = 5e5 + 10;

int c, n, m, d, q;

int w[M];

vector < pair < int, ll > > a[M];

ll f[N][N];

void solve () {
	cin >> c >> n >> m >> d >> q;

	rep (i, 1, m) cin >> w[i];

	rep (i, 1, n) {
		int k, x, v; 

		cin >> k;
		rep (j, 1, k) {
			cin >> x >> v;
			a[x].push_back ({i, v});
		}
	}

	rep (i, 1, n) rep (j, 1, n) f[i][j] = 1e16;
	rep (i, 1, n) f[i][i] = 0;

	rep (i, 1, m) {
		rep (l, 0, (int)a[i].size() - 1) rep (r, l + 1, (int)a[i].size() - 1) {
			auto [x, v1] = a[i][l];
			auto [y, v2] = a[i][r];

			f[x][y] = f[y][x] = min (min(f[x][y], f[y][x]), (ll)v1 + v2);	
		}
	}

	rep (k, 1, n) rep (i, 1, n) rep (j, 1, n) {
		if (k == i || k == j || i == j) continue;

		f[i][j] = min (f[i][j], f[i][k] + f[k][j]);
	}

	rep (i, 1, q) {
		int x, y; cin >> x >> y;

		ll ans = 1e16;

		for (auto [p1, v1] : a[x]) for (auto [p2, v2] : a[y]) 
			ans = min (ans, w[x] + v1 + w[y] + v2 + f[p1][p2]);

		cout << ans << '\n';
	}
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);

	int t = 1;
	// cin >> t;
	while (t --) solve ();
}

/*
g++ subway.cpp -o subway.exe -O2 -Wall -Wextra -std=c++14
*/
