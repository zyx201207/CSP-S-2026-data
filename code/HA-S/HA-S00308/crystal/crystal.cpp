#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 500010;
ll n, m, a[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll ans = 1;
	for (ll l = 1, r = 2, res = 0; r <= n; r++) {
		res += (r - l) * (a[r] - a[r - 1]);
		while (res > m) {
			res -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}
