#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 2e6;
int c;
ll n, d, a[N + 5], ans;
void solve() {
	ans = 0;
	for(int i = 1; i <= n; ++i) {
		auto it = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
		if(it == i) continue;
		ll lst[2] = {i, it}, ct = 0;
		for(ll j = it + 1; j <= n; ++j) {
			if(a[lst[1]] + d < a[j]) {
				auto itt = lower_bound(a + 1, a + n + 1, a[j - 1] - d) - a;
				ct += lst[1] - itt;
				lst[0] = lst[1], lst[1] = j - 1;
			}
			if(lst[0] == lst[1] || ct > 1) break;
			auto itt = lower_bound(a + 1, a + n + 1, a[j] - d) - a;
			if(ct + lst[1] - itt == 1) ++ans;
			if(j < n && a[j] + d < a[j + 1]) break;
		}
	}
	cout << ans << '\n';
}
void solveb() {
	ll p = 0, l = 1, r = n;
	for(ll i = 1; i <= n; ++i) 
	  if(a[i] - a[1] <= d && a[n] - a[i] <= d) {
	  	p = i; break;
		}
	if(p == 1 || p == n) {
		cout << 0 << endl; return;
	}
	ll cnta[2] = {0, 0}, cntb[2] = {0, 0};
	for(; l < p; ++l) {
		auto it = upper_bound(a + 1, a + n + 1, a[l] + d) - a;
		if(it == p + 1) ++cnta[0];
		if(it == p + 2) ++cnta[1];
	}
	for(; r > p; --r) {
		auto it = lower_bound(a + 1, a + n + 1, a[r] - d) - a;
		if(it == p) ++cntb[0];
		if(it == p - 1) ++cntb[1];
	}
	cout << cnta[0] * cntb[1] + cnta[1] * cntb[0] << '\n';
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
  ios::sync_with_stdio(0), cin.tie(0);
  int t; cin >> c >> t;
  while(t--) {
  	cin >> n >> d;
	  for(int i = 1; i <= n; ++i) cin >> a[i];
	  if(c == 13 || c == 14) solveb();
	  else solve();
	}
	return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13

ans=2
*/
