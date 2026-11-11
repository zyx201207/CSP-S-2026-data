#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, m;
bool fpa = 1;
ll a[200010];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if ((1 << ((ll) log2(a[i]))) != a[i]) {
			fpa = 0;
		}
	}
	if (m == 1) {
		ll mx = 0;
		for (int i = 1; i <= n; i++) {
			mx = max(mx, a[i]);
		}
		cout << mx;
	} else if (m == n) {
		ll ans = a[1];
		for (int i = 2; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans;
	} else if (m == 2) {
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
	} else if (fpa) {
		sort(a + 1, a + n + 1, greater<ll>());
		ll ans = a[1];
		for (int i = 2; i <= m; i++) {
			ans &= a[i];
		}
		cout << ans;
	} else {
		ll ans = 0; 
		for (int mask = 0; mask < (1 << n); mask++) {
			ll ad = (1 << n) - 1, cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (mask & (1 << (i - 1))) {
					ad &= a[i];
					cnt++;
				}
			}
			if (cnt != m) {
				continue;
			}
			ans = max(ans, ad);
		}
		cout << ans;
	}
	return 0;
}
/*
4 2
3 15 12 12
12

5 3
31 3 1 15 7
7
*/
