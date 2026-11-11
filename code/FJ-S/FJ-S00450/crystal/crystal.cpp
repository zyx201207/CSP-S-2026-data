#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 5;
ll a[N], b[N];
ll n, m;
bool check(ll x) {
	ll minn = 1e18;
	for(ll i = 1; i <= n - x + 1; i++) {
		ll sum = 0;
		for(ll j = i; j < i + x - 1; j++) sum += b[j] * (j - i + 1);
		minn = min(minn, sum);
		if(minn <= m) return true;
	}
	return false;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	ll s = 0;
	for(ll i = 1; i <= n; i++) {
		cin >> a[i];
		s += (a[i] - a[i - 1]) * i;
	}
	sort(a + 1, a + n + 1);
	if(s <= m) {
		cout << n << endl;
		return 0;
	}
	ll d = a[2] - a[1];
	bool flag = true;
	for(ll i = 2; i <= n; i++) {
		if(a[i] - a[i - 1] != d) flag = false;
	}
	if(flag) {
		ll sum = 0;
		for(ll i = 2; i <= n; i++) {
			sum += (i - 1);
			if(sum * d > m) {
				cout << i - 1 << endl;
				return 0;
			}
		}
		cout << n << endl;
		return 0;
	}
	else {
		for(ll i = 2; i <= n; i++) b[i - 1] = a[i] - a[i - 1];
		ll l = 1, r = n;
		while(l < r) {
			ll mid = (l + r) / 2;
			if(check(mid)) l = mid + 1;
			else r = mid - 1;
		}
		cout << l - 1 << endl;
	}
	return 0;
}
