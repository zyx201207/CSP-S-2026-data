#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll N = 2e5 + 10;
const ll K = 32 + 10;

ll ans[N];
ll op[N];
ll a[N];

ll n, m;

int main() {
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;
	
	for (ll i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	for (ll k = K - 10; k >= 0; k --) {
		ll cnt = 0;
		
		for (ll i = 1; i <= n; i ++) {
			if (op[i] == 0 && ((a[i] >> k) & 1) == 1) {
				cnt ++;
			}
		}
		
		if (cnt >= m) {
			for (ll i = 1; i <= n; i ++) {
				if (((a[i] >> k) & 1) == 0) {
					op[i] = 1;
				}
			}
			ans[k] = 1;
		} else {
			ans[k] = 0;
		}
	}
	
	ll sum = 0;
	for (ll k = K - 10; k >= 0; k --) {
		if (ans[k]) {
			sum += (1 << k);
		}
	}
	cout << sum << "\n";

	return 0;
}

