// 32 
// 15:28 START!
// <think>
// HARD!!!
// </think>
#include <bits/stdc++.h>
using namespace std;
#define int ll
using ll = long long; using pi = pair<int, int>;
#define Fr(i, s, t) for (int i(s); i <= (t); ++i)
#define Bk(i, t, s) for (int i(t); i >= (s); --i)
inline int rd() {
	int x(0), f(1), c; while ((c = getchar()) < 48 || c > 57) f = c ^ 45;
	do x = x * 10 + (c & 15); while ((c = getchar()) > 47 && c < 58); return f ? x : -x;
}
namespace _1 {
constexpr int N = 510;
int n, D, a[N], d[N][N], nxt[N], vis[N], ans; 
inline void Main() {
    n = rd(), D = rd(), ans = 0;
    Fr(i, 1, n) nxt[i] = 0;
    Fr(i, 1, n) Fr(j, 1, n) d[i][j] = 4e18;
    Fr(i, 1, n) a[i] = rd();
    Fr(i, 2, n) a[i] += 1 - a[1]; a[1] = 1;
    Fr(i, 1, n) {
    	int j;
    	for (j = i; j < n && a[j + 1] - a[i] <= D; ++j);
    	nxt[i] = j;
	}
	Fr(i, 1, n) {
		d[i][i] = 0;
		Fr(j, i + 1, nxt[i]) d[i][j] = 1;
	}
	Fr(k, 1, n) Fr(i, 1, n) Fr(j, 1, n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    Fr(l, 1, n) Fr(r, l + 1, n) {
    	if (d[l][r] >= 4e18) break;
    	int fg = 0;
    	for (int i = l; i < r; i = nxt[i]) vis[i] = 1;
		Fr(i, l + 1, r - 1) if (!vis[i] && d[l][i] + d[i][r] == d[l][r]) ++fg;
    	for (int i = l; i < r; i = nxt[i]) vis[i] = 0;
		if (fg == 1) ++ans; 
	}
	printf("%lld\n", ans);
}
}
namespace _2 {
constexpr int N = 2e6 + 10;
int n, d, a[N];
inline void Main() {
	n = rd(), d = rd();
	Fr(i, 1, n) a[i] = rd();
    d = d / (a[2] - a[1]);
    if (!d || d == 1) puts("0");
    else printf("%lld\n", max(n - d * 2 + 1, 0ll));
}
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c = rd();
	if (c <= 6) Bk(T, rd(), 1) _1::Main();
	if (c == 11 || c == 12) Bk(T, rd(), 1) _2::Main();
}
/*
+= id
cnt = 1 2

*/
