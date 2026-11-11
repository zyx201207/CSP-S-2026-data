#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 500005;
ll a[N];
ll check(ll mid) {
	ll ans = 0;
	for(ll i = 1; i <= mid; i++) ans += (a[mid] - a[i]);
	return ans; 
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m, ans = 0;
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	ll l = 0, r = n + 1, mid;
	while(l + 1 != r) {
		mid = l + r >> 1;
		if(m - check(mid) > 0) l = mid;
		else if(m - check(mid) < 0) r = mid;
		else break;
	} 
	ans += mid; 
	for(ll i = mid + 1; i <= n; i++) {
		if(a[i] == a[mid]) ans++;
	}
	cout << ans;
	return 0;
} 
