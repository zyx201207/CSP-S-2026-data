#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[500010] = {0};
ll n, m;
bool abc (ll x) {
	for (int i = 1; i < n; i++) {
		ll sum = 0;
		for (int j = 1; j <= x + i; j++) {
			sum += j * (a[i + j] - a[i + j - 1]);
		}
		if (sum <= m) return 1;
	}
	return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + 1 + n);
	ll l = 0, r = n, mid;
	while (l < r) {
		mid = (l + r + 1) / 2;
		if (abc(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l;
	return 0;
}
