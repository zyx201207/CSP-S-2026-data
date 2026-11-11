// 王名扬 GZ-S00063 观山湖区铭苑中学 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (auto &x : a)
		cin >> x;
	sort(a.begin(), a.end());
	
	vector<ll> diff(n - 1);
	bool flag = false;
	for (ll i = 0; i < n - 1; ++i) {
		diff[i] = a[i + 1] - a[i];
		if (diff[i] != diff[max(ll(0), i - 1)])
			flag = true;
	}

if (flag) {
	ll ans = 0;
	for (ll i = 0; i < n - 1; ++i) {
		ll res = 1, cnt = 0;
		for (ll j = i, k = 1; j < n - 1; ++j, ++k) {
			if (cnt + k * diff[j] <= m)
				cnt += k * diff[j], ++res;
			else
				break;
		}
		ans = max(ans, res);
	}
	cout << ans << '\n';
	return 0;
}

	ll d = a[1] - a[0];
	ll k = 1;
	for (;__int128(d) * k * (k + 1) <= __int128(2) * m; ++k);
	cout << k << '\n';
}
