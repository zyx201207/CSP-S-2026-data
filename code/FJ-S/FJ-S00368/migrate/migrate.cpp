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

const ll N = 2e6 + 5;
ll a[N], pre[N], nxt[N], f[N], g[N], h[N], sf[N], sg[N], A[N], B[N];
ll cnt[1005][1005];

void solve() {
	ll n = rd(), d = rd(), ans = 0;
	for(ll i = 1; i <= n; i++) a[i] = rd();
	for(ll i = 1, j = 1; i <= n; i++) {
		j = max(j, i + 1);
		while(j < n && a[j + 1] - a[i] <= d) j++;
		if(j <= n && a[j] - a[i] <= d) {
			if(i == 1 || a[j] - a[i - 1] > d) nxt[i] = j;
			else nxt[i] = 0;
		} else nxt[i] = 0;
	}
	for(ll i = n, j = n; i; i--) {
		j = min(j, i - 1);
		while(j > 1 && a[i] - a[j - 1] <= d) j--;
		if(j && a[i] - a[j] <= d) {
			if(i == n || a[i + 1] - a[j] > d) pre[i] = j;
			else pre[i] = 0; 
		} else pre[i] = 0;
	}
	for(ll i = 1; i <= n; i++) f[i] = f[pre[i]] + 1;
	for(ll i = n; i; i--) g[i] = g[nxt[i]] + 1;
	
	
//	for(ll i = 1; i <= n; i++) cout << pre[i] << " \n"[i == n];
//	for(ll i = 1; i <= n; i++) cout << nxt[i] << " \n"[i == n];
//	for(ll i = 1; i <= n; i++) cout << f[i] << " \n"[i == n];
//	for(ll i = 1; i <= n; i++) cout << g[i] << " \n"[i == n];

	for(ll i = 1; i <= n; i++) h[i] = 0;
	for(ll i = 1; i <= n; i++) if(nxt[i]) h[nxt[i]] += f[i] - 1;
	for(ll i = 1; i <= n; i++) if(pre[i] && pre[i] + 1 < i) ans += h[pre[i] + 1] * (g[i] - 1);
//	cout << ans << '\n';

	for(ll i = 1; i <= n; i++) if(nxt[i] && nxt[i] > i + 1) {
		ll l = upper_bound(a + i, a + n + 1, a[nxt[i] - 2] + d) - a;
		ll r = upper_bound(a + i, a + n + 1, a[nxt[i] - 1] + d) - a - 1;
//		cout << "[f]" << i << ' ' << nxt[i] << ' ' << l << ' ' << r << '\n';
		ans += (f[i] - 1) * (r - l + 1);
	}
	for(ll i = 1; i <= n; i++) if(pre[i] && pre[i] < i - 1) {
		ll l = lower_bound(a + 1, a + i - 1, a[pre[i] + 1] - d) - a;
		ll r = lower_bound(a + 1, a + i - 1, a[pre[i] + 2] - d) - a - 1;
//		cout << "[g]" << i << ' ' << pre[i] << ' ' << l << ' ' << r << '\n';
		ans += (g[i] - 1) * (r - l + 1);
	}
//	for(ll i = 1; i <= n; i++) sf[i] = sf[i - 1] + f[i], sg[i] = sg[i - 1] + g[i];
	for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++) cnt[i][j] = 0;
	for(ll i = 3; i < n; i++) {
		ll lf = lower_bound(a + 1, a + i - 1, a[i] - d) - a;
		ll rf = lower_bound(a + 1, a + i - 1, a[i + 1] - d) - a - 1;
		ll lg = upper_bound(a + i, a + n + 1, a[i - 2] + d) - a;
		ll rg = upper_bound(a + i, a + n + 1, a[i - 1] + d) - a - 1;
//		ans += (sf[rf] - sf[lf - 1]) * (sg[rg] - sg[lg - 1]);
//		ans += (sf[rf] - sf[lf - 1]) * (rg - lg + 1);
//		ans += (rf - lf + 1) * (sg[rg] - sg[lg - 1]);
		ans += (rf - lf + 1) * (rg - lg + 1);
//		cout << i - 1 << ' ' << i << " : " << "[" << lf << ',' << rf << "]   [" << lg << ',' << rg << "]\n";
//		for(ll j = lf; j <= rf; j++) A[j] = i;
//		for(ll j = lg; j <= rg; j++) B[j] = i;
//		for(ll j = lf; j <= rf; j++) {
//			for(ll k = lg; k <= rg; k++) {
//				for(ll x = j; x; x = pre[x]) {
//					for(ll y = k; y; y = nxt[y]) {
//						cnt[x][y]++;
//					}
//				}
//			}
//		}
	}
//	for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++) ans += (cnt[i][j] == 1);
//	for(ll i = 1; i <= n; i++) if(!pre[i]) {
//		for(ll j = i; j <= n; j++) if(!pre[j]) {
//			ll lstx = 0, lsty = 0;
//			for(ll x = i, y = j; x; x = nxt[x]) {
//				while(y && y < x) y = nxt[y];
//				if(!y) break;
//				if(A[x] != B[y]) break;
//			}
//		}
//	}
	cout << ans << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ll TESTID = rd();
	for(ll _ = rd(); _--; ) solve();
	return 0;
}
/*
0 1
10 3
-100 -97 -94 -93 -92 -91 -90 -89 -86 -83

0 1
10 3
0 3 6 7 8 9 10 11 14 17

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

0 1
7 663
-1000 -558 -116 105 326 547 989
*/


