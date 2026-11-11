#include <bits/stdc++.h>
#define int long long
#define pii std::pair< int, int >
const int N = 2e6 + 5, sN = 5005;
int c, n, d, a[N], L[N], R[N], f[sN][sN], g[sN][sN];
signed main() {
	freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	int T; std::cin >> c >> T; while (T--) {
		std::cin >> n >> d;
		for (int i = 1; i <= n; ++i) std::cin >> a[i];
		for (int i = 1; i <= n; ++i) {
			int l = 1, r = i - 1, A = i;
			while (l <= r) {
				int mi = (l + r) >> 1;
				if (a[i] - a[mi] <= d) A = mi, r = mi - 1;
				else l = mi + 1;
			} L[i] = A;
			l = i + 1, r = n, A = i;
			while (l <= r) {
				int mi = (l + r) >> 1;
				if (a[mi] - a[i] <= d) A = mi, l = mi + 1;
				else r = mi - 1;
			} R[i] = A;
		}
//		for (int i = 1; i <= n; ++i) std::cout << "[" << L[i] << ", " << R[i] << "]\n";
		if (c <= 10) { // N <= 5000
			int cnt = 0;
			for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) f[i][j] = g[i][j] = 0;
			for (int l = 1; l <= n; ++l) {
				f[l][l] = 1, g[l][l] = 0;
				for (int r = l + 1; r <= n; ++r) g[l][r] = g[l][std::max(l, L[r])] + 1;
				for (int r = l + 1; r <= n; ++r) {
					int li = std::max(L[r], l), ri = r - 1, A = li;
					while (li <= ri) {
						int mi = (li + ri) >> 1;
						if (g[l][mi] == g[l][A]) li = mi + 1, A = mi;
						else ri = mi - 1;
					}
					f[l][r] = f[l][A] - f[l][std::max(L[r], l) - 1];
					if (f[l][r] == 2) ++cnt;
					f[l][r] = f[l][r - 1] + f[l][r];
				}
			}
			std::cout << cnt << "\n";
		} else if (c <= 12) { // A
			int v = R[1] - 1;
			if (v == 0 || v == 1) std::cout << "0\n";
			else std::cout << std::max(n - 2 * v + 1, 0ll) << "\n";
		} else if (c <= 14) { // B
			int k, cnt = 0;
			for (int i = 1; i <= n; ++i)
				if (L[i] == 1 && R[i] == n) k = i;
			std::map< int, int > mp;
			for (int i = k + 1; i <= n; ++i) ++mp[L[i]];
			for (int i = 1; i <= k - 1; ++i) cnt += mp[R[i] - 1];
			std::cout << cnt << "\n";
		}
	}
	return 0;
}
/*
观察一下这个 T3，怎么是数数，不是很想做啊，先看 T4 吧。
算了 T4 好像更难，bro 还是老老实实看 T3 吧。 

感觉 T1、T2 纯大众题，T3、T4 一个不会感觉很慌啊。 

最短路恰好为 2 这个条件看起来非常苛刻，考虑刻画一下。
设岛屿 i 可达的最远（靠右）的岛屿为 d[i]。 
那么 u 到 v 的其中一条最短路肯定为 u, d[u], d^2[u], ..., d^{len-1}[u], v。
其中 d^k[u] = d[d^{k-1}[u]]。d^len[u] 不能等于 v，因为这样就不可能存在第二条最短路。
那么该如何保证只存在额外恰好 1 条最短路？
// 不是这个 yyh 出去几次了？监考老师不管吗 
首先任意 d[d^k[u]-1] != d^{k+1}[u]，这个应该是容易发现的。
然后想不出来了。。/ll

观察一下特殊性质吧。 
---
A：等差数列，那么所有的 d[u] - u 的值都是相同的，设其为 v。当且仅当 y-x = 2v - 1 的时候是合法的。
好像是的吧待会写个代码验证一下。

大样例过了，应该对了（ 
---
B：找到这样的岛屿是容易的，设其为 k。那么两个点的距离至多为 2 了。
分别找到所有点最左和最右能够到达的点 L[u] 和 R[u]。
那么只有 u \in [1, k - 1], v \in [k + 1, n] [L_v, R_u] 这段区间只有且仅有两个数的时候才可能。
应该也是对的，不过我也不确定就是了。

小样例过了； 
不过没有大样例，差评。 
---
C：距离至多为 10，感觉很意义不明，咕了。 
---
暴力：N <= 5000 的点看起来很可做，胡一个 O(n^2) 的做法。
可以胡一个 dp？令 f[l, r] 为从 l 到 r 的最短路方案数。
那么 f[l, r] = \sum _ {j \in [L[r], r)} f[l, j]，嗯看起来也是对的（
随便用前缀和什么的优化一下就行了。 
哦是假的（ 
别搞啊不能连 n <= 5000 都不会啊。 

枚举起点 u，终点 v，令 d[u, v] 为 u 到 v 的最短路。
g[u, v] = g[u, max(L[v], u)] + 1
那么用这个辅助转移 f：
f[u, v] = \sum _ {j \in [L[r], r), g[u, j] = g[u, L[r]]} f[u, j]
这个转移的决策区间仍然是一段连续的值 [L[r], ?]，这个 ? 可以通过二分确定，这回总该对了吧？ 

大样例过了，应该对了（ 
---

[16:52] 所以目前是完成了 56 分，意义重大啊（？） 
*/

