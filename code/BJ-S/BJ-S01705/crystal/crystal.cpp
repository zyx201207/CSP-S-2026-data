#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005];
ll sum[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (ll i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + a[i];
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ll l = 1;
		ll r = i;
		while (l <= r) {
			ll mid = (l + r) / 2;
			if (mid*a[i]-(sum[i]-sum[i-mid]) <= m) {
				ans = max(ans, mid);
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
