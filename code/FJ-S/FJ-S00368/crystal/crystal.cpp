#include <bits/stdc++.h>
#define ll long long
#define inf 2147483647
using namespace std;

inline ll rd() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}

const ll N = 5e5 + 5;
ll a[N], s[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n = rd(), m = rd(), ans = 0;
	for(ll i = 1; i <= n; i++) a[i] = rd();
	sort(a + 1, a + n + 1);
	for(ll i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for(ll i = 1, j = 0; i <= n; i++) {
		while(j < i && a[i] * (i - j) - (s[i] - s[j]) > m) j++;
		ans = max(ans, i - j);
	}
	cout << ans << '\n';
	return 0;
}
/*

*/

