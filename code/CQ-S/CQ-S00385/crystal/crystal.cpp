#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll N = 5e5 + 5;
ll n, m;
ll a[N];
bool check(ll x) {
	ll sum = 0;
	for (ll i = 1; i < x; i++) sum += a[i];
	for (ll i = x; i <= n; i++) {
		sum += a[i];
		sum -= a[i - x];
		if (a[i] * x - sum <= m) return 1;
	}
	return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + n + 1);
	ll l = 1, r = n, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << l - 1;
	return 0;
}
