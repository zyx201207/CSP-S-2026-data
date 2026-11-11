#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 5e5 + 10;
ll n, m;
ll a[N];
ll d[N];
ll ans = 0;
ll cnt[21];
bool isA = 1, isB = 1;

void dfs(ll pos, ll lst) {
	if(pos == n + 1) {
//		ll mx = 0;
//		for(ll i = 0; i <= 20; i ++) cout << cnt[i] << " \n"[i == 20];
		ans = max(ans, *max_element(cnt, cnt + 20));
		return;
	}
	for(ll i = 0; i <= lst; i ++) {
		cnt[a[pos]] --;
		cnt[a[pos] + i] ++;
		dfs(pos + 1, lst - i);
		cnt[a[pos] + i] --;
		cnt[a[pos]] ++;
	}
}

void solve() {
	cin >> n >> m;
	for(ll i = 1; i <= n; i ++) {
		cin >> a[i];
		if(a[i] != i) isA = 0;
	}
	sort(a + 1, a + n + 1);
	for(ll i = 2; i <= n; i ++) {
		d[i] = a[i] - a[i - 1];
		if(i > 2 && d[i] != d[i - 1]) isB = 0;
	}
	if(n <= 5) {
		for(ll i = 1; i <= n; i ++) cnt[a[i]] ++;
		dfs(1, m);
		cout << ans;
	}
	else if(isA) {
		if(sqrt(1 + 8 * m) >= 0) {
			cout << min<ll>(n, (- 1 + sqrt(1 + 8 * m)) / 2 + 1);
		}
		else cout << 1;
	}
	else if(isB) {
		ll k = d[2];
//		cout << k << ' ';
		if(sqrt(k * k + 8 * m * k) >= 0) {
			cout << min<ll>(n, (- k + sqrt(k * k + 8 * m * k)) / (2 * k) + 1);
		}
		else cout << 1; 
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	solve();
	
	return 0;
} 
