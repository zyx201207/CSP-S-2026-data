// ЭѕУћбя GZ-J00087 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ll n;
	cin >> n;
	vector<ll> a(n + 1);
	vector<char> c(n + 1);
	ll sum = 0;
	for (ll i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i], sum += a[i];
	}
	ll half = sum / 2;
	ll i = 1, j = n, oki = 0, okj = 0;
	ll ans = 0;
	ll tot = 0;
	for (; tot < half;) {
		if (a[i] - oki < a[j] - okj) {
			if (c[i] != c[j])
				ans += a[i] - oki;
			okj += a[i] - oki;
			tot += a[i] - oki;
			++i, oki = 0;
		} else if (a[i] - oki > a[j] - okj) {
			if (c[i] != c[j])
				ans += a[j] - okj;
			oki += a[j] - okj;
			tot += a[j] - okj;
			--j, okj = 0;
		} else {
			if (c[i] != c[j])
				ans += a[i] - oki;
			tot += a[i] - oki;
			++i, --j, oki = 0, okj = 0;
		}
	}
	
	cout << ans << '\n';
}
