#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 2e6 + 10;

ll mn[N], cnt[N];
ll a[N];

ll c, t;

int main() {
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t;
	
	while (t --) {
		ll n, d;
		cin >> n >> d;
		
		for (ll i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		
		ll ans = 0;
		
		for (ll i = 1; i <= n; i ++) {
			memset(mn, 0, sizeof(mn));
			memset(cnt, 0, sizeof(cnt));
			
			mn[i] = 0;
			cnt[i] = 1;
			for (ll j = i + 1; j <= n; j ++) {
				ll op = 0;
				ll sum = 0;
				ll mmn = 1e18;
				for (ll k = i; k < j; k ++) {
					if (a[j] <= a[k] + d) {
						if (op == 1) {
							if (mn[k - 1] < mn[k]) {
								break;
							}
						}
						
						mmn = min(mmn, mn[k] + 1);
						sum += cnt[k];
						
						op = 1;
					}
				}
				mn[j] = mmn;
				cnt[j] = sum;
				
				if (cnt[j] == 2) {
					ans ++;
				}
			}
		}
		
		cout << ans << "\n";
	}

	return 0;
}

