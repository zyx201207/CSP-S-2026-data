#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 2e5 + 10;
ll n, m;
ll a[N];
ll ans = 0;

void dfs(ll pos, ll num, ll cnt) {
	if(pos == n + 1) {
		if(cnt == m) {
			ans = max(ans, num);
		}
		return;
	}
	if((n - pos) < (m - cnt)) return;
	if(cnt > m) return;
	dfs(pos + 1, num, cnt);
	dfs(pos + 1, num & a[pos + 1], cnt + 1);
}

void solve() {
	cin >> n >> m;
	for(ll i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	if(m == 1) {
		cout << *max_element(a + 1, a + n + 1);
		return;
	}
	if(m == n) {
		ans = a[1];
		for(ll i = 2; i <= n; i ++) {
			ans &= a[i];
		}
		cout << ans;
		return;
	}
	if(m == 2) {
		for(ll i = 1; i <= n; i ++) {
			for(ll j = i + 1; j <= n; j ++) {
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return;
	}
	if(n <= 20) {
		for(ll i = 1; i <= n; i ++) {
			dfs(i, a[i], 1);
		}
		cout << ans;
		return;
	}
	return;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	solve();
	
	return 0;
}
