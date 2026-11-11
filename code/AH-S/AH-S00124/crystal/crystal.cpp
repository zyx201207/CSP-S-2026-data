#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[500010], s[500010], s2[500010], mn = 9e18;
ll sum(ll l, ll r) {
	return s2[r] - s2[l - 1] - (l - 1) * (a[r] - a[l]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i], mn = (i != 1 ? min(mn, a[i] - a[i - 1]) : 9e18);
	if (mn > m) {
		cout << 1; return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
		s2[i] = (i - 1) * a[i] - s[i - 1];
	}
	ll l = 1, r = 1, ans = 0;
	for (; r <= n;) {
		while (r <= n && sum(l, r) <= m) r++;
		ans = max(ans, r - l);
		while (l <= r && sum(l, r) > m) l++;
	}
	cout << ans << endl;
	return 0;
}

