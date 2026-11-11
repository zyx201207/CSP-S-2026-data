#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n;
	ll m;
	cin >> n >> m;
	ll a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int ans = 1;
	ll k = 0;
	for (ll i = 1; i < n; i++) {
		ll req = (i - k) * (a[i] - a[i - 1]);
		while (m < req) {
			m += (a[i] - a[k]);
			k++;
		}
		m -= req;
		int b = i + 1 - k;
		if (b > ans) ans = b;
	}
	cout << ans;
	return 0;
}
