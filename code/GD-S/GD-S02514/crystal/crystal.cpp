#include<bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = (l) ; i <= (r) ; i ++)
#define per(i, l, r) for (int i = (r) ; i >= (l) ; i --)

using ll = long long;

const int N = 5e5 + 10;

int n;

ll m;

ll a[N];

void solve () {
	cin >> n >> m;

	rep (i, 1, n) cin >> a[i];

	sort (a + 1, a + 1 + n);

	int L = 1, ans = 0;

	ll S = 0;

	rep (i, 1, n) {
		while (S > m) S -= a[i] - a[L ++];

		ans = max (ans, i - L + 1);

		if (i != n) {
			ll d = a[i + 1] - a[i];
			S += (d * (i - L + 1));
		}
	}

	cout << ans << '\n';
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);

	int t = 1;
	// cin >> t;
	while (t --) solve ();
}

/*

5 5 
1 2 4 8 9

5 8
-3 -1 2 2 7

*/