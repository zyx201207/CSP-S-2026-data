/*
我每次往右飞到尽量远的距离，一定是一条最短的路线 vec1
设另一条是 vec2
有 vec1[i - 1] < vec2[i] <= vec2[i]
那么 vec1 和 vec2 不同的只有一个
（否则我可以构造一个 vec3，使用 最后一个不同点）
且这个唯一的不同点相邻

也就是只存在一个 vec1[i] - 1 能到 vec1[i + 1]
且这个唯一的 i 还得满足 vec1[i - 1] - 1 不能到 vec1[i] - 1
然后任何 vec1[i] - 2 都不能到 vec1[i + 1]

vec[0] = u, vec[len] = v, vec[i] = next[vec[i - 1]]

如果是 vec[i] (i != 0) 可被替换
i <= len - 2 要求 next[vec[i] - 1] == next[vec[i]]
i == len - 1 要求 next[vec[i] - 1] >= v

我称满足前者的是 永久可被替换点（状态 1），因为即使 v 再往右它仍然满足
找到 u 跳 next （不包括 u）的第 1, 2 个 永久可被替换点，设为 m1, m2
v <= m1 代表有 临时可被替换点
m1 < v <= m2 代表 m1 是 可被替换点

我再设如果 next[i - 1] + 1 == next[i]，那么 next[i] 不得是 可被替换点，我称 i 为状态 -1

先看 v <= m1
有 next[vec[len - 1] - 1] >= v && next[vec[len - 1] - 2] < v && (len == 2 || vec[len - 2] 为状态 0)
即 next[vec[len - 1] - 2] < v <= next[vec[len - 1] - 1] && (len == 2 || vec[len - 2] 为状态 0)
我可以枚举 vec[len - 1]，满足 len == 2 || vec[len - 2] 为状态 0 就加上 next[vec[len - 1] - 1] - next[vec[len - 1] - 2]
我尝试继承 next[u] 的答案来算 u 的答案

如果 v > m1
首先不能再有 临时可被替换点 了
即 next[vec[len - 1] - 1] < v
而且 next[m1 - 2] != next[m1 - 1]，m1 的上一个点为 u 或状态 0
这个我就对 m1 找它以后有多少可能的 v
定义 dp[i] 表示 i 到 m1[i] 之间满足 next[vec[len - 1] - 1] < v 的 v
*/
#include <stdio.h>
#include <algorithm>
constexpr int N = 2000000;
int c, T, n;
long long d, a[N + 5];
int next[N + 5], m1[N + 5], m1last[N + 5], m2[N + 5];
int dp[N + 5], dpnear[N + 5];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while (~--T)
	{
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; ++i)
			scanf("%lld", a + i);
		for (int i = 1, j = 1; i <= n; ++i)
		{
			while (j != n && a[j + 1] - a[i] <= d)
				++j;
			next[i] = i == j ? -1 : j;
		}
		for (int i = n; i >= 1; --i)
		{
			if (next[i] == -1 || next[next[i]] == -1)
				m1[i] = m2[i] = m1last[i] = -1;
			else
				if (next[next[i] - 1] == next[next[i]])
				{
					m1[i] = next[i];
					m1last[i] = i;
					m2[i] = m1[next[i]];
				}
				else
				{
					m1[i] = m1[next[i]];
					m1last[i] = m1last[next[i]];
					m2[i] = m2[next[i]];
				}
		}
		long long ans = 0;
		// v <= m1
		for (int u = n; u >= 1; --u)
		{
			dp[u] = 0;
			dpnear[u] = 0;
			if (next[u] == -1)
				continue;
			if (next[next[u]] == -1)
				continue;
			if (m1[u] == next[u]) // next is m1
				continue;

			dp[u] = dp[next[u]];
			if (next[next[u] - 1] + 1 == next[next[u]])
				dp[u] -= dpnear[next[u]];
			if (next[u] != u + 1)
				dp[u] += dpnear[u] = next[next[u] - 1] - next[next[u] - 2];
			ans += dp[u];
		}

		// v > m1
		for (int u = n; u >= 1; --u)
		{
			dp[u] = 0;
			if (next[u] == -1)
				continue;
			dp[u] = next[u] - std::max(next[u - 1] == next[u] ? next[u - 2] : next[u - 1], u);
			if (m1[u] != next[u])
				dp[u] += dp[next[u]];

			if (m1[u] == -1)
				continue;
			if (next[m1[u] - 2] != next[m1[u] - 1] && (m1last[u] == u || next[m1last[u] - 1] + 1 != m1[u]))
				ans += dp[m1[u]];
		}
		printf("%lld\n", ans);
	}
	return 0;
}

// 17 : 01