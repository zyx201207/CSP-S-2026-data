#include <bits/stdc++.h>
typedef long long ll;
const ll N = 6e5 + 10;
using namespace std;
ll n, m;
ll a[N], s[N];
ll qqwe(ll l, ll r, ll val) {
	ll f = (r - l + 1) * val;
	f -= (s[r] - s[l - 1]);
	return f;
}
int main() {
	freopen("crystal.in", "r", stdin); 
	freopen("crystal.out", "w", stdout); 
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (ll i = 1; i <= n; ++i) {
		s[i] = a[i] + s[i - 1];
	}
	// cout << '\n';
	ll res = 0;
	for (ll i = 2; i <= n; ++i) {
		ll l = 1, r = i;
		while (l < r) {
			ll mid = (l + r) >> 1;
			ll tmp = qqwe(mid, i, a[i]);
			if (tmp <= m) r = mid;
			else l = mid + 1;
		}
		// cout << l << '\n';
		ll k = (i - l + 1);
		res = max(res, k);
	}
	cout << res << '\n';
	return 0;
} 

/*
5 8
-3 -1 2 2 7
5 5
1 2 4 8 9 
*/
