#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e5 + 5;

int a[N], n, m, x, f[35], nf[35];

void solve () {
	std :: cin >> n >> m;
	std :: vector <int> v;
	for (int i = 1; i <= n; i ++) {
		std :: cin >> a[i];
		for (int j = 32; ~j; j --) {
			f[j] += (a[i] >> j) & 1;
		}
		v.push_back (a[i]);
	}
	std :: vector <int> nv;
	int ans = 0;
	for (int k = 32; ~k; k --) {
//		std :: cout << k << '\n';
		if (f[k] >= m) {
			ans |= (1ll << k);
			for (int i : v) {
				if ((i >> k) & 1) {
					nv.push_back (i);
//					std :: cout << i << ' ';
				}
			}
//			std :: cout << '\n';
			for (int j = 32; ~j; j --) {
				f[j] = 0;
			}
			for (int i : nv) {
				for (int j = k - 1; ~j; j --) {
					f[j] += (i >> j) & 1;
				}
			}
			v.swap (nv);
			nv.clear ();
		}
	}
	std :: cout << ans;
}

/*
4 2 3 15 12 12
*/

signed main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	std :: ios :: sync_with_stdio (false), std :: cin.tie (0), std :: cout.tie (0);
//	int TTT; std :: cin >> TTT; while (TTT --)
	solve ();

	return 0;
}

