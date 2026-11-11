#include "iostream"
#include "algorithm"
#include "cmath"
#include "queue"
#include "vector"
#define int long long
const int N = 5e5 + 5;
const int mod = 1e9 + 7;
template <class T> inline void gmax (T &x, T y) {if (x < y) x = y;}
template <class T> inline void gmin (T &x, T y) {if (x > y) x = y;}
template <class T> inline void gadd (T &x, T y) {x = (x + y) % mod;}
template <class T> inline void gmul (T &x, T y) {x = x * y % mod;}
#define fi first
#define se second
#define pb push_back
int n, m, a[N], dif[N], qian[N];
signed main () {
	freopen ("crystal.in", "r", stdin); freopen ("crystal.out", "w", stdout);
	std :: cin.tie (0) -> std :: ios :: sync_with_stdio (false);
	std :: cin >> n >> m; for (int i = 1; i <= n; ++i) std :: cin >> a[i]; 
	std :: sort (a + 1, a + n + 1);
	for (int i = 2; i <= n; ++i) dif[i] = a[i] - a[i - 1];
	for (int i = 1; i <= n; ++i) qian[i] = qian[i - 1] + dif[i];
	int ans = 0, cnt = 0, sum = 0, last = 2; 
	for (int i = 2; i <= n; ++i) {  
		++cnt; if (sum + cnt * dif[i] <= m) gmax (ans, cnt + 1), sum += cnt * dif[i];
		else { int cur = sum + cnt * dif[i];
			while (cur > m) {
				--cnt; cur -= qian[i] - qian[last - 1]; ++last; 
			} sum = cur; 
		} 
//		std :: cout << i << ' ' << cnt + 1 << ' ' << sum << '\n';
	} gmax (ans, cnt + 1); std :: cout << ans << '\n';
//	for (int i = 1; i <= n; ++i) std :: cout << a[i] << ' ';
	return 0;
}


/*
17 分钟过T1，太有感觉了 
30 20
1 1 2 2 4 5 5 12 22 23 25 36 37 38 40 41 41 46 49 56 56 70 75 76 77 84 86 86 93 93

*/ 
