#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 2e5 + 5;

ll a[N];

bool cmp (ll x, ll y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); 
	
	ll n, m;
	cin >> n >> m;
	
	bool flag = true;
	
	ll maxNum = 0;
	
	for (ll i = 1;i <= n;i ++) {
		cin >> a[i];
		if (a[i] != i - 1) {
			flag = false;
		}
		maxNum = max(maxNum, a[i]);
	}
	
	sort(a + 1, a + 1 + n, cmp);
	
	if (n <= 30) {
		ll ans = 0;
		for (ll id = 0;id <= (1 << n);id ++) {
			ll cnt = 0;
			ll num = 0;
			for (ll i = 1;i <= n;i ++) {
				if (id & (1 << (i - 1))) {
					cnt ++;
					if (cnt == 1) {
						num = a[i];
					} else {
						num &= a[i];
					}
				}
			}
			
			if (cnt == m) {
				ans = max(ans, num);
			}
		}
		cout << ans;
	} else if (m == 1) {
		cout << a[1];
	} else if (m == 2) {
		ll ans = 0;
		for (ll i = 1;i <= n;i ++) {
			for (ll j = i + 1;j <= n;j ++) {
				ans = max(ans, (a[i] & a[j]));
			}
		}
		cout << ans;
	} else if (m == n) {
		ll ans = a[1];
		for (ll i = 2;i <= n;i ++) {
			ans = ans & a[i];
		}
		cout << ans;
	} else if (m == n - 1) {
		ll ans = a[1];
		for (ll i = 2;i <= m;i ++) {
			ans = (ans & a[i]);
		}
		cout << ans;
	} else if (flag) {
		ll ans = a[1];
		for (ll i = 2;i <= m;i ++) {
			ans = (ans & a[i]);
		}
		cout << ans;
	} else if (maxNum <= 4) {
		cout << "4";
	} else {
		ll ans = a[1];
		for (ll i = 2;i <= m;i ++) {
			ans = (ans & a[i]);
		}
		cout << ans;
	}
	return 0;
}

/*
50
*/
