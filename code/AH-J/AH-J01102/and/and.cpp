#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
typedef long long ll;
int a[N];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, m, maxn = -1;
	cin >> n >> m;
	for (ll i = 0; i < n; i ++) {
		cin >> a[i];
	}
	sort(a, a + n);
	if (m == 1) {
		cout << a[n - 1];
		return 0;
	}
	if (m == n) {
		ll tmp = a[0];
		for (ll i = 1; i < n; i ++) {
			tmp &= a[i];
		}
		cout << tmp;
		return 0;
	}
	if (m == 2) {
		for (ll i = 0; i < n; i ++) {
			for (ll j = i + 1; j < n; j ++) {
				ll ans = (a[i] & a[j]);
				maxn = max(maxn, ans);
			}
		}
		cout << maxn;
	}
	return 0;
}
