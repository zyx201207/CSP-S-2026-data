#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int INF = 0x3f3f3f3f, _INF = 0xc0c0c0c0;
const ll LLINF = 0x3f3f3f3f3f3f3f3f, _LLINF = 0xc0c0c0c0c0c0c0c0;

/*
首先，两个节点之间长度最短的路径，是可以通过 DP O(1) 求得的。

对于这道题，显然你不能枚举每对点。那怎么办呢？

首先观察这个双径岛屿对有什么性质。

这是 T3，我应该还没有能耐 A 这道题。 所以考虑部分分。

n <= 300 应该是简单的。24pts。你考虑对于每个区间直接去算。

如果我们已经知道了一段的 DP 值，怎么知道它是不是双径对呢？

记 dp[i] 表示到某个位置的最短飞行次数。

考虑如果我们能从这个序列中找到恰好两个子串 1 2 3 4 5... dp[v]，那么这就是一个合法的串。

我们考虑记录一个地方可能是由几个地方转移来的。

具体就是维护一个桶，记录当前各个数出现的次数。
 
这是不是能做到 O(n^2)？你可能还需要一个单调队列状物来维护最小值。

这就有 40pts 了。

考虑有没有有用的特殊性质。

首先是等差数列，也就是每个点之间的距离相同。

那么你就可以考虑小鸟一次可以飞跃 x 个岛屿。

这是否是一个结论：如果 v - u = 2x - 1，就可以？

好像是的。现在 48pts。

考虑特殊性质 B：有一个所谓万能岛屿。

考虑一段航线包含这个万能岛屿。那么距离肯定不超过 2.

但是这似乎对是否是符合要求的段没有任何影响？不，其实是有的。

既然是这样，显然，这个岛屿左侧的点和右侧的点，全都可以互相抵达。

我们先写 48pts 吧。 

我可能在饭堂。

你考虑我们后面转移 buc 的时候，也不能累加不在范围之内的。

那就不太好做了。

不过，你可以处理失效的 dp 值。

17:54 48pts 
*/

//#define int long long

const int N = 2e6 + 10;
int c, T, n; ll d; ll x[N];
int dp[N];
int q[N]; int h = 1, t = 0;
ll buc[N];
ll cnt[N];

void solve() {
	std::cin >> n >> d;
	ll ans = 0; 
	for (int i = 1; i <= n; i++) std::cin >> x[i];
	memset(dp, 0x3f, sizeof(int) * (n + 1));
	for (int k = 1; k <= n; k++) {
		dp[k] = 0;
		memset(buc, 0, sizeof(int) * (n + 1));
		buc[0] = 1;
		h = 1, t = 0;
		q[++t] = k;
		int last = k;
		for (int i = k + 1; i <= n; i++) {
			while (t >= h && x[q[h]] < x[i] - d) {
				h++;
			} 
			dp[i] = dp[q[h]] + 1;
			if (dp[i] >= INF) break;
			while (t >= h && dp[i] < dp[q[t]]) t--;
			q[++t] = i; 
			while (x[i] - x[last] > d && last < i) {
				buc[dp[last]] -= cnt[last];
				last++;
			}
			if (dp[i] >= 1) {
				buc[dp[i]] += buc[dp[i] - 1];
				cnt[i] = buc[dp[i] - 1];
				buc[dp[i]] = std::min(buc[dp[i]], LLINF);
//				if (buc[dp[i] - 1] > 2) break;
				if (buc[dp[i] - 1] == 2) {
					ans++;
				}
			}
		}
	}
	std::cout << ans << '\n';
}

void special() {
	std::cin >> n >> d;
	for (int i = 1; i <= n; i++) std::cin >> x[i];
	ll diff = x[2] - x[1];
	ll cnt = d / diff;
//	std::cerr << cnt << '\n';
	if (cnt <= 1) {
		std::cout << "0\n";
		return;
	}
	// 如果 cnt = 0，意味着什么？ 
	// 如果 v - u == 2 * cnt - 1，就满足条件。
	std::cout << std::max(0ll, n - (2 * cnt - 1)) << '\n'; 
	
	// 现在会出现该输出 0 的不输出 0.
	 
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::ios::sync_with_stdio(false); std::cin.tie(0);

	std::cin >> c >> T;
	while (T--) {
		if (c == 11 || c == 12) special();
		else solve();
	}

	return 0;
}

