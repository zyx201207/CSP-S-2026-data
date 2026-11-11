#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[200005], ans;
ll q(ll x) {
	ll sum = 0;
	while (x) {
		sum += x % 2;
		x /= 2;
	}
	return sum;
}
void dfs (ll sum, ll x, ll i) {
	if (sum == m) {
		ans = max(ans, x);
		return;
	}
	if (i > n) {
		return;
	}
	dfs(sum + 1, a[i] & x, i + 1);
	dfs(sum, x, i + 1);
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(0, a[1], 1);
	cout << ans;
	return 0;
}
