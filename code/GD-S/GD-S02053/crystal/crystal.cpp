#include <bits/stdc++.h> 

#define FstIO ios::sync_with_stdio(0) 
#define pii pair <ll, ll> 
#define pb push_back 
#define pbk pop_back 
#define fi first 
#define se second 

using namespace std; 
using ll = long long; 
using ld = long double; 
using ull = unsigned long long; 

const ll N = 1e6 + 5, M = 200; 
const ld eps = 1e-6; 
const ll mod = 998244353, inf = 1e18; 

ll n, m, ans; 
ll A[N], p[N]; 

ll solve(ll u) {
	ll l = 1, r = u, res = u; 
	while (l <= r) {
		ll mid = l + r >> 1; 
		ll nd = p[u] - p[mid - 1]; 
		nd = (u - mid + 1) * A[u] - nd; 
		if (nd <= m) 
			res = mid, r = mid - 1; 
		else
			l = mid + 1; 
	}
	return u - res + 1; 
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

signed main() {
	freopen("crystal.in", "r", stdin); 
	freopen("crystal.out", "w", stdout); 
	
	FstIO; 
	
	cin >> n >> m; 
	for (ll i = 1; i <= n; ++ i ) cin >> A[i]; 
	sort(A + 1, A + n + 1); 
	for (ll i = 1; i <= n; ++ i ) 
		p[i] = p[i - 1] + A[i]; 
	for (ll i = 1; i <= n; ++ i ) 
		ans = max(ans, solve(i)); 
	cout << ans << '\n'; 
	
	return 0; 
}
