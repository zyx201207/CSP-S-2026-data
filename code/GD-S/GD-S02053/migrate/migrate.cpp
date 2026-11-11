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

const ll N = 2e6 + 5, M = 600; 
const ld eps = 1e-6; 
const ll mod = 998244353, inf = 1e18; 

ll c, t, n, d; 
ll x[N], pre[N]; 
ll f[N], g[N]; 
// pre[i] : i 前面第一个能跳到 i 的 
void Subtask() {
	cin >> n >> d; 
	for (ll i = 1; i <= n; ++ i ) cin >> x[i], pre[i] = 0; 
	for (ll i = 1; i <= n; ++ i ) {
		for (ll j = 1; j < i; ++ j ) {
			if (abs(x[i] - x[j]) <= d) {
				pre[i] = j; 
				break; 
			}
		}
	}
	ll ans = 0; 
	for (ll i = 1; i <= n; ++ i ) {
		for (ll j = 1; j <= n; ++ j ) f[j] = inf, g[j] = 0; 
		f[i] = 0; g[i] = 1;  
//		cout << "calc " << i << '\n'; 
		for (ll j = i + 1; j <= n; ++ j ) {
// 			cout << "j " << j << '\n'; 
			if (pre[j]) {
				ll pr = max(i, pre[j]); 
				f[j] = f[pr] + 1; 
				ll l = pr, r = j, p = pr; 
				while (l <= r) {
					ll mid = l + r >> 1; 
					if (f[mid] + 1 == f[j]) 
						p = mid, l = mid + 1; 
					else
						r = mid - 1; 
				}
				g[j] += g[p] - g[pr - 1]; 
				/*
				for (ll k = max(i, pre[j]); k <= j; ++ k ) {
					if (f[j] == f[k] + 1) 
						g[j] += g[k]; 
//					cout << k << ' ' << f[k] + 1 << '\n'; 
				} 
				*/
			}
//			cout << f[j] << ' ' << g[j] << '\n'; 
			ans += (g[j] == 2); 
//			if (g[j] == 2) 
//				cout << "ok " << i << ' ' << j << '\n'; 
			g[j] += g[j - 1]; 
		}
	}
	cout << ans << '\n'; 
}
void Subtask2() {
	cin >> n >> d; 
	for (ll i = 1; i <= n; ++ i ) cin >> x[i]; 
	ll bt = x[2] - x[1]; 
	if (d < bt || n == 1) {
		cout << "0\n"; 
		return ; 
	}
	d = d - (d % bt); 
	ll p = d / bt; 
	if (p == 1) {
		cout << "0\n"; 
		return ; 
	}
	p <<= 1; 
	if (p > n) cout << "0\n"; 
	else cout << n - p + 1 << '\n'; 
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
7 8
1 5 9 13 17 21 25

0 1
6 4
1 2 5 6 7 8

6

0 10
1 3
1000000000000000000
2 1999999999999999995
-1000000000000000000 999999999999999995
5 857142857142857142
-999999999999999999 -142857142857142857 428571428571428571 714285714285714285 999999999999999999
6 1199999999999999994
-1000000000000000000 -600000000000000002 -200000000000000004 199999999999999994 599999999999999992 999999999999999990
4 1199999999999999994
-999999999999999995 199999999999999999 599999999999999997 999999999999999995
5 999999999999999999
-1000000000000000000 -333333333333333334 -1 333333333333333332 999999999999999998
6 4
999999999999999993 999999999999999994 999999999999999995 999999999999999996 999999999999999997 1000000000000000000
7 3
-4 -2 0 1 2 3 5
6 3
-3 0 1 2 3 4
8 461538461538461535
-1000000000000000000 -692307692307692310 -538461538461538465 -230769230769230775 384615384615384605 692307692307692295 846153846153846140 999999999999999985
10 1999999999999999970
-899999999999999986 -699999999999999989 -499999999999999992 -299999999999999995 -99999999999999998 99999999999999999 299999999999999996 499999999999999993 699999999999999990 899999999999999987

*/

signed main() {
	freopen("migrate.in", "r", stdin); 
	freopen("migrate.out", "w", stdout); 
	
	FstIO; 
	
	cin >> c >> t; 
	for (ll _ = 1; _ <= t; ++ _ ) {
		if (11 <= c && c <= 12) {
			Subtask2(); 
			continue; 
		}
		Subtask(); 
	}
	
	
	return 0; 
}
