#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 5e5 + 10;

ll a[N];
ll s[N];

ll n, m;

ll sum(ll l, ll r) {
	return s[r] - s[l - 1];
}

ll erfen(ll R) {
	ll l = 1, r = R;
	ll L = -1;
	
	while (l <= r) {
		ll mid = (l + r) / 2;
		
		if ((R - mid + 1) * a[R] - sum(mid, R) <= m) {
			L = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	
	return L;
}
int main() {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for (ll i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + 1 + n); //
	
	for (ll i = 1; i <= n; i ++) {
		s[i] = s[i - 1] + a[i];
	}
	
	ll ans = 0;
	for (ll i = 1; i <= n; i ++) {
		ll L = erfen(i);
		
		ans = max(ans, i - L + 1);
	}
	
	cout << ans << "\n";
	
	return 0;
}
