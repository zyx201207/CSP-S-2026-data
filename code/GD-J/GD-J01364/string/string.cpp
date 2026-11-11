#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
const ll N = 2e5 + 3;
struct {
	ll x;
	char c;
}a[N];
ll n;
void solve() {
	cin >> n;
	for (ll i = 1;i <= n;++i) {
		cin >> a[i].x >> a[i].c;
	}
	ll l = 1, r = n;
	ll ans = 0;
	for (;l < r;) {
		ll x = min(a[l].x, a[r].x);
		ans += x * (a[l].c != a[r].c);
		a[l].x -= x, a[r].x -= x;
		while (!a[l].x) l++;
		while (!a[r].x) r--;
	}
	cout << ans << '\n';
	return;
}
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll _ = 1;
//	cin >> _;
	while (_--) {
		solve();
	}
}

