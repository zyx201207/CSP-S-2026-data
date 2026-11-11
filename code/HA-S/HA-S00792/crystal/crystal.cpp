#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define qep(i, a, b) for(int i = (a); i >= (b); i --) 
#define ll long long
#define i128 __int128
#define ull unsigned long long
#define pb push_back
#define fi first
#define se second
//#define int long long
using namespace std;

const int N = 500010;
ll a[N], s[N], n, m;

bool check(ll j, ll i) {
	if((i - j + 1) * a[i] - s[i] + s[j - 1] <= m) return 1;
	return 0;
}

void solution() {
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	rep(i, 1, n) s[i] = s[i - 1] + a[i];
	ll ans = 1;
	rep(i, 1, n) {
		ll l = 1, r = i, res = i;
		while(l <= r) {
			ll mid = (l + r) >> 1;
			if(check(mid, i)) r = mid - 1, res = mid;
			else l = mid + 1;
		}
//		cout << res << '\n';
		ans = max(ans, i - res + 1);
	}
	cout << ans << '\n';
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solution();	
	return 0;
}
