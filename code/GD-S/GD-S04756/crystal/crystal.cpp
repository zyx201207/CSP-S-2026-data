#include <bits/stdc++.h>
#ifdef LOCALENV
	#define cerr(x) cerr x
#else
	#define cerr(x)
#endif
using ll = long long;
using namespace std;
int main() {
	#ifndef LOCALENV
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	#endif
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; // n in [1, 5e5]
	ll m; // m in [0, 1e18]
	cin >> n >> m;
	vector<ll> a(n); // abs(a[i]) <= 1e12
	for (ll &_: a)
		cin >> _;
	
	sort(a.begin(), a.end());
	
	int l = 0, r = 0, res = 1;
	ll cst = 0;
	for (l = 0; l <= n - 1; l++) {
//		cerr << l << endl;
//		cerr(<< "l = " << l << endl);
		if (l > 0) {
//			cst += (a[l - 1] - a[l]);
			cst -= (a[r] - a[l - 1]);
		}
		while (true) {
			if (r < n - 1) {	
				ll nCst = cst + (a[r + 1] - a[r]) * (r - l + 1);
//				cerr(<< "LEN: " << r - l + 1 << " L: " << l << " " << "R: " << r + 1 << " CST: " << nCst << endl);
				if (nCst <= m) {
					cst = nCst;
					r++;
					res = max(res, r - l + 1);
//					cerr(<< "ROK: " << r << endl);
				} else break;
			} else break;
		}
	}
	cout << res;
	return 0;
}
