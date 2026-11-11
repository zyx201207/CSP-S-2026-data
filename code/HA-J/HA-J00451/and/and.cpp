#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 200010;
ll n, m, a[N];
bool flag[N];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	for (ll i = 29; i >= 0; i--) {
		ll cnt = 0;
		for (ll j = 1; j <= n; j++) {
			if ((!flag[j]) && ((a[j] >> i) & 1)) {
				cnt++;
			}
		}
		if (cnt < m) continue;
		ans |= (1 << i);
		for (ll j = 1; j <= n; j++) {
			if (!((a[j] >> i) & 1)) {
				flag[j] = true;
			}
		}
	}
	cout << ans;
	return 0;
}
