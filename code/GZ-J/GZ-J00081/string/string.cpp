//GZ-J00081 贵阳市第一中学 王羿翔 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	ll n; cin >> n;
	vector<pair<ll, char> > a(n + 1);
	for (ll i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
	}
	ll ans = 0;
	ll i = 1, j = n;
	while (i < j) {
		ll use = min(a[i].fi, a[j].fi);
		a[i].fi -= use; a[j].fi -= use;
		if (a[i].se != a[j].se) ans += use;
		if (a[i].fi == 0) i++;
		if (a[j].fi == 0) j--;
	}
	cout << ans;
	return 0;
}
