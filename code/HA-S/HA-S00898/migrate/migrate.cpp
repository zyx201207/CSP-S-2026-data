#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dmin(pair<int, int>& a, const pair<int, int>& b) {
	if (b.first + 1 < a.first) {
		a = make_pair(b.first + 1, b.second);
	} else if (b.first + 1 == a.first) {
		a.second += b.second;
	}
	a.second = min(a.second, 3);
}
void solve() {
	ll n, d, ans = 0;
	cin >> n >> d;
	vector<ll> x(n + 10);
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i < n; i++) {
		vector<pair<int, int>> dp(n + 5, make_pair(0x3f3f3f3f, 0));
		dp[i] = make_pair(0, 1);
		for (int j = i; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (x[k] - x[j] > d) break;
				dmin(dp[k], dp[j]);
			}
		}
		for (int j = i + 1; j <= n; j++) ans += (dp[j].second == 2);
	}
	cout << ans << '\n';
}
void solve1() {
	ll n, d, ans = 0;
	cin >> n >> d;
	vector<ll> x(n + 10);
	for (int i = 1; i <= n; i++) cin >> x[i];
	if (n == 1) {
		cout << 0 << '\n';
		return;
	}
	ll l = x[2] - x[1];
	if (d < 2 * l) {
		cout << 0 << '\n';
		return;
	}
	ll sk = d / l;
	for (int i = 1; i <= n; i++) {
		if (i + sk + sk - 1 <= n) ans++;
	}
	cout << ans << '\n';
}
void solve2() {
	ll n, d, ans = 0;
	cin >> n >> d;
	vector<ll> x(n + 10);
	for (int i = 1; i <= n; i++) cin >> x[i];
	if (n == 1) {
		cout << 0 << '\n';
		return;
	}
	vector<ll> nxt(n + 10, 0), pre(n + 10, 0), prelen(n + 10, 0), nxtlen(n + 10, 0);
	int p = 1;
	for (int i = 2; i <= n; i++) {
		while (p < i && x[i] - x[p] > d) p++;
		if (x[i] - x[p] <= d) pre[i] = p;
	}
	p = n;
	for (int i = n - 1; i >= 1; i--) {
		while (p > i && x[p] - x[i] > d) p--;
		if (x[p] - x[i] <= d) nxt[i] = p;
	}
	for (int i = 1; i <= n; i++) {
		if (pre[i]) prelen[i] = prelen[pre[i]] + 1;
	}
	for (int i = n; i >= 1; i--) {
		if (nxt[i]) nxtlen[i] = nxtlen[nxt[i]] + 1;
	}
	for (int i = 1; i <= n; i++) {
		if (pre[i] && nxt[i]) {
			int flag1 = (i - pre[i] >= 3 && x[nxt[i]] - x[i - 1] <= d && x[nxt[i]] - x[i - 2] > d) || (i - pre[i] == 2 && x[nxt[i]] - x[i - 1] <= d);
			int flag2 = (nxt[i] - i >= 3 && x[i + 1] - x[pre[i]] <= d && x[i + 2] - x[pre[i]] > d) || (nxt[i] - i == 2 && x[i + 1] - x[pre[i]] <= d);
			if (flag1 + flag2 == 1) ans += (ll) prelen[i] * nxtlen[i];
		}
	}
	cout << ans << '\n';
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	if (c == 11 || c == 12) while (t--) solve1();
	else if (c <= 6) while (t--) solve();
	else while(t--) solve2();
	return 0;
}
