//Task2: subway
/*
把每条地铁线路看成一个点，跑完全图最短路，用 dijikstra算法解决
时间复杂度 
O(m+n^2logn+qd^2)
考场电脑跑 1.2s 
期望得分 100pts 
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair <long long, long long> pll;
const long long N = 550, M = 500010;
long long n, m, q, k[N], d, w[M], c, x, y, xx, yy, dis[N][N], ans, minn, h;
vector <pll> a[N], s[M];
priority_queue <pll> p;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis, 0x3f, sizeof dis);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (long long i = 1; i <= m; i++)
		scanf("%lld", &w[i]);
	for (long long i = 1; i <= n; i++)
		dis[i][i] = 0;
	for (long long i = 1; i <= n; i++)
	{
		scanf("%lld", &k[i]);
		for (long long j = 1; j <= k[i]; j++)
		{
			scanf("%lld%lld", &x, &y);
			a[i].push_back(make_pair(x, y));
			s[x].push_back(make_pair(i, y));
		}
	}
	for (long long i = 1; i <= n; i++)
	{
		for (auto j : a[i])
		{
			x = j.first;
			y = j.second;
			for (auto z : s[x])
			{
				xx = z.first;
				yy = z.second;
				dis[i][xx] = min(dis[i][xx], y + yy);
				dis[xx][i] = min(dis[xx][i], y + yy);
			}
		}
	}
	for (long long i = 1; i <= n; i++)
	{
		while(!p.empty())
			p.pop();
		dis[i][i] = 0;
		minn = LONG_LONG_MAX;
		for (long long j = 1; j <= n; j++)
		{
			if (j == i)
				continue;
			p.push(make_pair(dis[i][j], j));
		}
		while(!p.empty())
		{
			x = p.top().second;
			if (dis[i][x] < p.top().first)
			{
				p.pop();
				continue;
			}
			p.pop();
			for (long long j = 1; j <= n; j++)
			{
				if (dis[i][j] > dis[i][x] + dis[x][j])
				{
					dis[i][j] = dis[i][x] + dis[x][j];
					p.push(make_pair(dis[i][j], j));
				}
			}
		}
	}
	while(q--)
	{
		scanf("%lld%lld", &x, &y);
		ans = LONG_LONG_MAX;
		for (auto xx : s[x])
			for (auto yy : s[y])
				ans = min(ans, dis[xx.first][yy.first] + xx.second + yy.second);
		printf("%lld\n", ans + w[x] + w[y]);
	}
}
