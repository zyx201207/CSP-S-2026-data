#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
首先看我会什么
暴力建图跑floyd
然后枚举中转点
如果中转点里面恰好两个点是等于min的
那么ret++
复杂度n^3 24pts
（一定要写的！） 
然后特殊性质B看起来很善良
由于存在一个岛屿使得。。。
那么很显然的xn-x1<=2d
这个题很像模拟赛里面的那啥题（
如果不会我是不是就变成智障了

那么很显然的，距离<=2
然后我们发现了一个东西，由于保证了一个什么岛屿xi单增
实际上岛屿可以到达的区间我们是可以直接维护的
类似bound一下就好了
这个时候大概可以线段树优化建图一下之类的
继续观察
这个傻逼玩意要求的是恰好2
对于一个起点u，让它一直跳
显然u一次只能跨越一个区间
但是如果这连个区间的交集大于2了，那么这个区间内的点就pass掉了
也就是说u必须向着它能跳的区间的最后两个点跳，否则就挂了
比如说如果是两步的
那么就是跳到最后两个上，这两个再跳，而且这两个能跳到的位置要严格大于倒三个能跳到的位置
那么答案就会+=这连个点能跳到的区间的并再扣掉倒三能跳到的区间
然后你继续推导就会发现一个很显然的问题
这个选两个点的过程只能进行一次，而且必须进行一次
也就是说，你还要枚举在什么位置用，这样就变成n^3了（
（而且还很不好写。。。。）

但是你发现2只有一次，是跳跃过程中自动产生的
也就是复杂度还是n^2


显然的，如果我们在如下图跑最短路，那么可能产生贡献的点对一定在上面
一个点向着自己最后能跳的两个点连边
这个时候就好了
如果使用dij，跑两遍dij就可以获得一个点的答案
你发现一个点的度数是2，转移没什么
就是一个点如果不跳最大的点
那么就是跳一个最大和次大都能到的点（我们先假设lb之后的数组是单调递增的）
 
 考虑等差数列，如果d>公差，那么数列必然单调递增
0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

*/
const int N = 500;
ll dis[N][N];
int g[N][N];
const int INF = 1e18 + 10;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		int n;
		ll d;
		cin >> n >> d;
		vector<ll> a(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
		}
		if (c == 11 || c == 12)
		{
			if (a[1] + d < a[3])
			{
				cout << 0 << "\n";
				continue;
			}
			if (a[1] + d >= a[3] && a[1] + d < a[4])
			{
				cout << n - 3 << "\n";
				continue;
			}
			else
			{
				cout << 0 << "\n";
				continue;
			}
		}
		if (c == 13 || c == 14)
		{
			int cnt = 0;
			int x = 0;
			int ret = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (a[1] + d >= a[i] && a[i] + d >= a[n]) cnt++, x = i;
			}
			if (cnt == 1)
			{
				for (int i = 1; i <= n; ++i)
				{
					if (a[i] + d >= a[x + 1] && a[i] + d < a[x + 2]) ret++;
				}
			}
			if (cnt == 2)
			{
				ret++;
				for (int i = 2; i <= n; ++i)
				{
					if (a[i] + d >= a[x] && a[i] + d < a[x + 1]) ret++;
				}
			}
			cout << ret; 
			continue;
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				dis[i][j] = INF;
				g[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				if (a[i] + d >= a[j]) dis[i][j] = 1, dis[j][i] = 1;
				else break;
			}
		}
		for (int k = 1; k <= n; ++k)
		{
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= n; ++j)
				{
					if (i != k && j != k)
					{
						dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
					}
				}
			}
		}
//		for (int i = 1; i <= n; ++i)
//		{
//			for (int j = 1; j <= n; ++j)
//			{
//				cout << dis[i][j] << " ";
//			}
//			cout << "\n";
//		}
//		cout <<"\n";
		int ret = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				for (int k = 1; k <= j; ++k)
				{
					if (i != k && j != k)
					{
						if (dis[i][k] + dis[k][j] == dis[i][j]) g[i][j]++;
					}
				}
					
			}
		}
//		for (int i = 1; i <= n; ++i)
//		{
//			for (int j = 1; j <= n; ++j)
//			{
//				if (g[i][j] == 2) ret++;
//				cout << g[i][j] << " ";
//			}
//			cout << "\n";
//		}
		cout << ret << "\n";
	}
}
