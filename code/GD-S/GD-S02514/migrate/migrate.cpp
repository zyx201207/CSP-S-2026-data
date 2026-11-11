#include<bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = (l) ; i <= (r) ; i ++)
#define per(i, r, l) for (int i = (r) ; i >= (l) ; i --)

using ll = long long;

const int N = 2e6 + 10;

int n;

ll d, x[N];

int R[N][21], r[N][21];
int L[N][21], l[N][21];

void solve () {
	cin >> n >> d;

	rep (i, 1, n) cin >> x[i];

	int p = 1;
	rep (i, 1, n) {
		while (x[p] - x[i] <= d && p <= n) p ++;
		R[i][0] = p - 1;

		if (R[i][0] != i) r[i][0] = p - 2;
		else r[i][0] = -1;

		// cerr << "R " << i << ' ' << R[i][0] << '\n';
	}

	p = n;
	per (i, n, 1) {
		while (x[i] - x[p] <= d && p > 0) p --;
		L[i][0] = p + 1;

		if (L[i][0] != i) l[i][0] = p + 2;
		else l[i][0] = -1;

		// cout << "L " << i << ' ' << L[i][0] << '\n';
	}


	rep (k, 1, 20) {
		rep (i, 1, n) {
			R[i][k] = R[R[i][k - 1]][k - 1];
			L[i][k] = L[L[i][k - 1]][k - 1];

			if (r[i][k] == -1) r[i][k] = r[R[i][k - 1]][k - 1];
			else if (r[R[i][k - 1]][k - 1] == -1) r[i][k] = R[r[i][k - 1]][k - 1];
			else r[i][k] = max (r[R[i][k - 1]][k - 1], R[r[i][k - 1]][k - 1]);

			if (l[i][k] == -1) l[i][k] = l[L[i][k - 1]][k - 1];
			else if (l[L[i][k - 1]][k - 1] == -1) l[i][k] = L[l[i][k - 1]][k - 1];
			else l[i][k] = max (l[L[i][k - 1]][k - 1], L[l[i][k - 1]][k - 1]);
		}
	}

	ll ans = 0;

	// rep (i, 1, n - 3) {
	// 	if (x[i + 2] - x[i] <= d && x[i + 3] - x[i + 1] <= d && x[i + 3] - x[i] > d) {
	// 	}
	// }

	rep (i, 2, n - 2) {
		if (R[i][0] == R[i + 1][0] && L[i][0] == L[i + 1][0]) {
			int x = L[i][0], y = R[i][0];

			int mxr = y;
			per (j, 20, 0) if (R[mxr][j] != r[mxr][j]) mxr = R[mxr][j];

			int mnl = x;
			per (j, 20, 0) if (L[mnl][j] != l[mnl][j]) mnl = L[mnl][j];

			ans += (mxr - y + 1) * (x - mnl + 1);

			// cerr << x << ' ' << i << ' ' << i + 1 << ' ' << y << '\n';
		
		}
	}

	cout << ans << '\n';
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);

	int t = 1, c;
	cin >> c >> t;
	while (t --) solve ();
}




/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

10 3
0 3 6 7 8 9 10 11 14 17

0 1

10 3
0 3 6 7 8 9 10 11 14 17
*/




