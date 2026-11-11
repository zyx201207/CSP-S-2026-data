// I often recall the past, For the CSP-S2026.
// WC 2027
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define rep2(i, a, b) for(int i=a; i>=b; i--)
const int N = (int)5e5 + 10;

ll n, m, a[N];
bool ck(ll id) {
	ll val = a[id], M = m;
	rep (i, 1, n-1) {
		if (M-(val-a[i]) >= 0) {
			M -= (val-a[i]);
		} else {
			return false;
		}
	}
	return true;
}
ll bs(ll l, ll r) {
	ll ans = 0;
	while (l < r) {
		ll mid = (l+r)>>1;
		if (ck(mid)) {
			l = mid+1;
			ans = mid;
		}
		else r = mid-1;
	}
	return ans;
}
void solve() {
	cin >> n >> m;
	rep (i, 1, n) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	ll ans = 0;
	rep (i, 1, n) {
		ans = max(ans, bs(1, i));		
	}

	cout << ans << endl;
}

int main() {
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	 
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
