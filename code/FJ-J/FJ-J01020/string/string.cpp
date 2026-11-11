// long long
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll N = 2e5 + 10;

ll a[N];
char c[N];

ll n;

int main() {
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	
	for (ll i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
	}
	
	ll l = 1, r = n;
	ll ans = 0;
	
	while (l < r) {
		ll tot = min(a[l], a[r]);
		
		a[l] -= tot;
		a[r] -= tot;
		
		if (c[l] != c[r]) {
			ans += tot;
		}
		
		if (a[l] == 0) {
			l ++;
		}
		if (a[r] == 0) {
			r --;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}


