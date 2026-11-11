#include "iostream"
#include "algorithm"
#include "cmath"
#include "queue"
#include "vector"
#define int long long 
const int N = 2e6 + 5;
const int mod = 1e9 + 7;
template <class T> inline void gmax (T &x, T y) {if (x < y) x = y;}
template <class T> inline void gmin (T &x, T y) {if (x > y) x = y;}
template <class T> inline void gadd (T &x, T y) {x = (x + y) % mod;}
template <class T> inline void gmul (T &x, T y) {x = x * y % mod;}
#define fi first
#define se second
#define pb push_back
int n, d, x[N], r[N]; 
int dis[5005][5005]; std :: pair <int, int> from[N];
inline void solve () { int ans = 0; 
	std :: cin >> n >> d; for (int i = 1; i <= n; ++i) std :: cin >> x[i]; x[n + 1] = 9e18;
	int ri = 1; for (int i = 1; i <= n; ++i) {
		while (x[i] + d >= x[ri + 1]) ++ri; r[i] = ri;
	}
	for (int i = 1; i <= n; ++i) {
		int j = 1, sum = 0, last = i; while (j <= n && j) {
			for (int k = last + 1; k <= j; ++k) dis[i][k] = sum; ++sum; if (j == n) break; last = j; j = r[j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 3; j <= n; ++j) {
			if (dis[i][j] == dis[i][j - 1] + 1 && dis[i][j - 2] + 1 == dis[i][j] && dis[i][j - 3] != dis[i][j]) ++ans;
		}
	} std :: cout << ans << '\n';
}
inline void solve2 () {
	std :: cin >> n >> d; for (int i = 1; i <= n; ++i) std :: cin >> x[i]; x[n + 1] = 9e18;
	int nex = 1; while (x[nex + 1] <= d + x[1]) ++nex;
	if (nex <= 2) std :: cout << "0\n";
//	else std :: cout << n << ' ' << nex << '\n';
	else std :: cout << std :: max (0ll, n - (nex - 1) * 2 + 1ll) << '\n'; 
}
signed main () {
	freopen ("migrate.in", "r", stdin); freopen ("migrate.out", "w", stdout);
	std :: cin.tie (0) -> std :: ios :: sync_with_stdio (false);
	int idx; int T; std :: cin >> idx >> T; while (T--) {
////		solve2 ();	
//		solve ();
		if (idx <= 10) solve ();
		else if (idx <= 12) solve2 ();
	}

	return 0;
}


/*
除去完全包含，交集有且仅有1个 
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

2 4 6 6 7 7 7
*/

