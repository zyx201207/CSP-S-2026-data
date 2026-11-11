#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
const ll N = 2e5 + 3;
const ll Log = 30;
const ll INF = (1LL << 30) - 1;
ll n, m;
ll a[N]; 
ll f[2003][2003];
void solve1() {
	f[0][0] = INF;
	for (ll i = 1;i <= n;++i) f[0][i] = INF;
	for (ll i = 1;i <= n;++i) f[i][0] = INF;
	for (ll i = 1;i <= n;++i) {
		for (ll j = 1;j <= i;++j) {
			ll x = ((f[i - 1][j] == INF)? 0 : f[i - 1][j]);
			f[i][j] = max((f[i - 1][j - 1] & a[i]), x);
		}
	}
	cout << f[n][m] << '\n';
	return;
}
ll tr[N][2], cnt;
ll vis[N];
ll s[N];
void insert(ll x) {
	ll p = 0;
	for (ll i = Log - 1;i >= 0;--i) {
		ll j = ((x >> i) & 1);
		if (!tr[p][j]) {
			tr[p][j] = ++cnt;
		}
		p = tr[p][j];
		vis[p]++;
		s[p] = j;
	}
}
bool check(ll x) {
	ll p = 0, res = 0;
	for (ll i = Log - 1;i >= 0;--i) {
		ll j = ((x >> i) & 1);
		if (j == 0) {
			if (s[p] == 1 && vis[p] >= m) return true;
			else if (tr[p][1]) p = tr[p][1];
			else p = tr[p][0];
		}
		else {
			if (s[p] == 1 && vis[p] >= m) res |= (1 << i);
			if (tr[p][1]) p = tr[p][1];
			else p = tr[p][0];
		}
		if (res >= x) return true;
	}
	return res >= x;
}
void solve() {
	cin >> n >> m;
	ll ma = 0;
	for (ll i = 1;i <= n;++i) {
		cin >> a[i];
		ma = max(ma, a[i]);
		insert(a[i]);
	}
	if (n <= 2000) {
		solve1();
		return;
	}
	ll l = 0, r = ma, ans = -1;
	ll mid;
	while (l <= r) {
		mid = (l + r) / 2;
		cout << l << ' ' << r << ' ' << mid << '\n';
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << '\n';
	return;
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll _ = 1;
//	cin >> _;
	while (_--) {
		solve();
	}
}

