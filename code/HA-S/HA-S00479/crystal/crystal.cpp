#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
ll a[500010], s[500010];

bool cmp(ll a, ll b) {
	return a < b;
}

bool check(ll x) {
	ll ans = 1e18;
	for(int i = 1; i <= n - x + 1; i ++) {
		ll xx = a[i + x - 1], cnt = 0;
		ans = min(ans, xx * (x - 1) - s[i + x - 2] + s[i - 1]);
	}
	return ans <= m;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	

	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	
	for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];

	ll l = 1, r = n;
	while(l < r) {
		ll mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	
	cout << l;

	return 0;
}
