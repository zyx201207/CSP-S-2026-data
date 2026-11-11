#include<iostream>
using namespace std;
using ll = int;
const ll N = 5e5 + 3;
ll n, m, a[N];
bool vis[N];
ll ans[N];
ll s[N];
void solve1() {
	for (ll i = 1;i <= n;++i) {
		for (ll j = 1;j <= m;++j) vis[j] = 0, s[j] = -1;
		for (ll j = i;j <= n;++j) {
			if (vis[a[j]]) {
				for (ll k = s[a[j]];k < j;++k) vis[a[k]] = 0;
			}
			vis[a[j]] = 1, s[a[j]] = j;
		}
		for (ll j = 1;j <= m;++j) ans[j] += vis[j];
	}
	for (ll i = 1;i <= m;++i) cout << ans[i] << ' ';
	cout << '\n';
}
void solve2() {
	ll x = a[1];
	for (ll i = 1;i <= n + 1;++i) {
		if (x != a[i]) {
			cout << i - 1 << ' ';
			x = a[i];
		}
	}
	cout << '\n';
}
void solve() {
	cin >> n >> m;
	bool f = 1;
	for (ll i = 1;i <= n;++i) {
		cin >> a[i];
		if (a[i] < a[i - 1] && i != 1) f = 0;
	}
	if (f) {
		solve2();
		return;
	}
	if (n <= 5000) {
		solve1();
		return;
	}
	return;
}
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll _ = 1;
//	cin >> _;
	while (_--) {
		solve();
	}
}

