/*
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll c, t;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c >> t;
	while (t--) {
		ll n, d;
		cin >> n >> d;
		vector<ll> a(n);
		for (ll i = 0; i < n; i++) cin >> a[i];
		for (ll i = 0; i < n; i++) {
			for (ll j = 1; j < n - i; j++) {
				if (abs(a[i + j] - a[i]) <= d) {
					for (ll x = i + j; x < n; x++) {
						
					}
				}
			}
		}
	}
	
	return 0;
}
*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll c, t;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c >> t;
	while (t--) {
		ll n, d;
		cin >> n >> d;
		vector<ll> a(n);
		vector<vector<ll>> dp(n, vector<ll>(n, 0));
		for (ll i = 0; i < n; i++) cin >> a[i];
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				if (abs(a[j] - a[j - 1]) <= d)
					dp[j - 1][j] = 1;
			}
		}
		ll ans;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dp[i][j] == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}

/*
#1
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

#2
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
