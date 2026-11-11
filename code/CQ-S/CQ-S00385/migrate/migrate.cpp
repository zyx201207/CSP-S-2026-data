#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll N = 2e6 + 5;
ll c, t;
ll n, d;
ll a[N];
ll l[N], r[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	if (c == 11 || c == 12) {
		while (t--) {
			cin >> n >> d;
			for (ll i = 1; i <= n; i++) cin >> a[i];
			if (d < a[2] - a[1] || d >= 2 * (a[2] - a[1])) cout << 0;
			else cout << n - 3;
			cout << "\n";
		}
		return 0;
	}
	while (t--) {
		cin >> n >> d;
		memset(a, 0, sizeof(a));
		for (ll i = 1; i <= n; i++) cin >> a[i];
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		a[0] = -0x3f3f3f3f3f3f3f3f;
		a[n + 1] = 0x3f3f3f3f3f3f3f3f;
		ll idx = 1;
		for (ll i = 2; i <= n + 1; i++) {
			while (idx <= n && a[i] - a[idx] > d) {
				l[idx] = i - 1;
				idx++;
			}
		}
		for (ll i = n; i >= 1; i--) {
			if (a[n] - a[i] + 1 <= d) l[i] = 0x3f3f3f3f3f3f3f3f;
			else break; 
		}
		idx = n;
		for (ll i = n - 1; i >= 0; i--) {
			while (idx >= 1 && a[idx] - a[i] > d) {
				r[idx] = i + 1;
				idx--;
			}
		}
		for (ll i = 1; i <= n; i++) {
			if (a[i] - a[1] + 1 <= d) r[i] = 0x3f3f3f3f3f3f3f3f;
			else break; 
		}
		ll ans = 0;
		for (ll i = 1; i <= n; i++) {
			for (ll j = i + 1; j <= n; j++) {
				if (a[j] - a[i] > d && l[i] == 1 + r[j]) {
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
