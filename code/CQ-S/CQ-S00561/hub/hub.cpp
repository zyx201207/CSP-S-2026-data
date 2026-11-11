/*
这个就是我选择一个点集 S，不超过 2 个连通块
要求距离 S 最远点的距离最小

考虑二分
假设有 dist
我选择一个点可以覆盖到距离 dist 的所有点

考虑把直径单独拎出来
两边往中间走 dist 距离的点肯定在 S 内
设为 u, v
在这两个点上扩展
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
void setmax(int& x, int y) { if (x < y) x = y; }
void setmin(int& x, int y) { if (x > y) x = y; }
constexpr int N = 1000000;
int c, T, n, k, depth[N + 5], father[N + 5];
std::vector<int> g[N + 5], vec;
void initdfs(int u, int fa, int d)
{
	depth[u] = d;
	father[u] = fa;
	for (int v : g[u])
		if (v != fa)
			initdfs(v, u, d + 1);
}
int height[N + 5];
void getheight(int u, int fa, int& cnt, int dist)
{
	height[u] = 0;
	for (int v : g[u])
		if (v != fa)
		{
			getheight(v, u, cnt, dist);
			setmax(height[u], height[v] + 1);
		}
	if (height[u] >= dist)
		++cnt;
}
int check(int dist)
{
	if (dist + dist + 1 >= vec.size())
		return 1;
	int l = dist;
	int r = vec.size() - 1 - dist;
	static int oppo[N + 5];
	int res = 2;
	for (int i = l + 1; i < r; ++i)
	{
		int cnt = 0;
		getheight(vec[i], 0, cnt, dist);
		if (cnt)
		{
			res += cnt - 1;
			setmax(oppo[i + 1], i);
		}
		else
			if (i + dist - height[vec[i]] + 1 <= r)
				setmax(oppo[i + dist - height[vec[i]] + 1], i - (dist - height[vec[i]]));
	}
	int m1 = l;
	int delta = r - l - 1;
	for (int m2 = l + 1; m2 <= r; ++m2)
	{
		setmax(m1, oppo[m2]);
		setmin(delta, m1 - l + r - m2);
	}
	for (int i = l; i <= r; ++i)
		oppo[i] = 0;
	return res + delta;
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while (~--T)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1, u, v; i < n; ++i)
		{
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		initdfs(1, 0, 0);
		int p1 = 0;
		for (int i = 1; i <= n; ++i)
			if (depth[i] > depth[p1])
				p1 = i;
		initdfs(p1, 0, 0);
		int p2 = 0;
		for (int i = 1; i <= n; ++i)
			if (depth[i] > depth[p2])
				p2 = i;
		for (int u = p2; u; u = father[u])
			vec.push_back(u);
		for (int i = 1; i < vec.size(); ++i)
		{
			g[vec[i - 1]].erase(std::find(g[vec[i - 1]].begin(), g[vec[i - 1]].end(), vec[i]));
			g[vec[i]].erase(std::find(g[vec[i]].begin(), g[vec[i]].end(), vec[i - 1]));
		}
		int l = 0, r = n;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (check(mid) <= k)
				r = mid;
			else
				l = mid + 1;
		}
		printf("%d\n", l);

		for (int i = 1; i <= n; ++i)
			g[i].clear();
		vec.clear();
	}
	return 0;
}

// 18 : 01
// 嗯，该干些什么好呢
// 希望不要挂分，我的 400 能保住吗