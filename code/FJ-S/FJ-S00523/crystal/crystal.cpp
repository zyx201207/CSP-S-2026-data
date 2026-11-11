#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 5e5;
ll n, m, a[N + 5], A[N + 5], ans = 1;
bool chk(ll t, ll p) {
	ll c = (p - t + 1) * a[p] - (A[p] - A[t - 1]);
	if(c <= m) return 1; return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)	A[i] = A[i - 1] + a[i];
	for(int i = 1; i <= n; ++i) {
		ll l = 1, r = i + 1, mid;
		while(l < r) {
			mid = (l + r) >> 1;
			if(chk(mid, i)) r = mid; else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
 	return 0;
}
