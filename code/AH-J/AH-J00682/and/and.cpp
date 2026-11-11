#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
ll a[N], d[N];
int n, m;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	ll ans;
	if (m == 1) {
		ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			ans = max(ans, a[i]);
		}
		cout << ans << '\n';
	} else if (m == n) {
		ans = 1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			ans &= a[i];
		}
		cout << ans << '\n';
	} else if (m == n-1) {
		ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			ll c = 1;
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				c &= a[i];
			}
			ans = max(ans, c);
		}
		cout << ans << '\n';
	} else if (m == 2) {
		ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			ll c = 1;
			for (int j = i+1; j <= n; j++) {
				c = (a[i] & a[j]);
				ans = max(ans, c);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
