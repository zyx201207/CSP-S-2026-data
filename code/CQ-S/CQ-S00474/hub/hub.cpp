#include <bits/stdc++.h>
using namespace std;
namespace WorldMachine {
	const int N = 15;
	int c, T, n, k, d[N][N];
	basic_string<int> G[N];
	void dfs(int u, int fa, int rt) {
		for (int v : G[u]) if (v ^ fa)
			d[rt][v] = d[rt][u] + 1, dfs(v, u, rt);
	}
	void solve() {
		cin >> n >> k;
		for (int i = 0; i < n; i++) G[i].clear();
		for (int i = 1, u, v; i < n; i++)
			cin >> u >> v, u--, v--, G[u] += v, G[v] += u;
		for (int i = 0; i < n; i++) d[i][i] = 0, dfs(i, -1, i);
		int ans = n;
		for (int i = 0; i < 1 << n; i++) {
			if (__builtin_popcount(i) != k) continue;
			int ce = 0;
			for (int u = 0; u < n; u++) if (i >> u & 1)
				for (int v : G[u]) if (i >> v & 1) ce++;
			ce >>= 1;
			if (ce < k - 2) continue;
			int mx = 0;
			for (int u = 0; u < n; u++) if (!(i >> u & 1)) {
				int mn = n;
				for (int v = 0; v < n; v++) if (i >> v & 1)
					mn = min(mn, d[u][v]);
				mx = max(mx, mn);
			}
			ans = min(ans, mx);
		}
		cout << ans << '\n';
	}
	void main() {
		cin >> c >> T;
		while (T--) solve();
	}
}
int main() {
	freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	return WorldMachine::main(), 0;
}
/*
一棵树，称点集 S 是好的，如果它在树上形成不超过两个连通块
求所有好的点集 S 中，每个点到 S 的距离的最大值之和
入死我都想不出来这种题 .jpg
如果只是一个连通块，最远的点一定是叶子，但这里有两个连通块所以不一样
可能更类似于“中点”？
暴力就是直接暴力，能拿 15 分
对于 一个连通块，常用的手段是树形 DP，固定当前的 u 为最高点
两个连通块怎么做呢？能否考虑分别 DP 两块，然后拼接起来？
首先为了避免算重，应该先确定，统计贡献的点应该是两块的最高点的 LCA
换而言之，对于当前 u，选择两棵 不同 子树，并在里面分别选择两个连通块，统计答案
简单地分析了问题的形式之后，回到我们要求的东西：距离 S 最远的点的距离
先考虑只有一个连通块怎么做喵 qvq
比较棘手的是父亲方向的子树，不过外面的最远点是可以确定的，设其为 p[u]
那么子树内的方案就要分成最远点 <= p[u] 和 > p[u] 两种
<= p[u] 相当于钦定了一些点必须被选，整个方案数看起来应该是可以计算的
需要在线查询 k 级后代的信息，写个线段树合并？时空复杂度 O(n log n)
好现在考虑两个连通块怎么做，在当前的 u 统计不同子树内选连通块的贡献
假设现在确定了两个连通块的最高点 x, y，然后再找到除开 x, y 子树外，距离 x, y 的最大距离 d
那么按照两边子树内最远距离是否 <= d 还能再分类，考虑这样能做到什么时间复杂度
好吧大概是 O(n^2 log n) 的，稍微优化一下应该能搞到 O(n^2)
你发现优化不动了，这个 d 的限制摆在这里简直是惊为天人，你稍微动一下直接就地动山摇
哦你吗我才看到有个 k 的限制？哈哈我草
绷不住了，滚回去看看 T3

草啊原来是求最小值吗？？？
*/
