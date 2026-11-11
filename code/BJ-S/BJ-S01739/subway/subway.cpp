/*
【题目描述】
B 市共有 m 个地铁站,编号为 1 到 m。每个地铁站都有一个站厅,地铁口与站厅
之间有一条通道,往返耗时相同。从第 v (1 ≤ v ≤ m) 个地铁站的地铁口走到站厅需要
w v 的时间。
B 市共有 n 条地铁线路,编号为 1 到 n,其中第 i (1 ≤ i ≤ n) 条线路经过 k i 个地
铁站,编号依次为 a i,1 , a i,2 , . . . , a i,k i 。在第 a i,j (1 ≤ j ≤ k i ) 个地铁站处,从站厅走到第 i
条线路的站台需要 t i,j 的时间,往返耗时相同。同一条线路不会重复经过同一个地铁站,
即 a i,1 , a i,2 , . . . , a i,k i 两两不同。
由于空间有限,每个地铁站最多有 d 条线路经过。此外,B 市的地铁网络是连通的,
即任意两个地铁站都可以通过若干条线路互相到达。
小 R 有 q 个出行计划。对于第 r (1 ≤ r ≤ q) 个出行计划,小 R 将从第 x r 个地铁
站的地铁口出发,乘坐地铁到达第 y r 个地铁站的地铁口,途中可能进行若干次站内换
乘。每次站内换乘都需要从一条线路的站台先走到站厅,再从站厅走到另一条线路的站
台。每个出行计划的总步行时间为进出站和换乘的步行时间之和。小 R 希望每个出行
计划的总步行时间都尽可能少。
你需要帮助小 R 求出,每个出行计划的最小总步行时间。
【输入格式】
从文件 subway.in 中读入数据。
输入的第一行包含五个非负整数 c, n, m, d, q,分别表示测试点编号、地铁线路数、
地铁站数、每个地铁站最多被几条线路经过,以及出行计划数。特别地,若 c = 0,则
该测试点为样例。
输入的第二行包含 m 个正整数 w 1 , w 2 , . . . , w m ,依次表示从每个地铁站的地铁口走
到站厅需要的时间。
输入的第 i + 2 (1 ≤ i ≤ n) 行包含 1 + 2k i 个正整数,其中第一个正整数为 k i ,表
示第 i 条线路经过的地铁站数;接下来 2k i 个正整数为 a i,1 , t i,1 , a i,2 , t i,2 , . . . , a i,k i , t i,k i ,其
中 a i,j 表示第 i 条线路经过的第 j 个地铁站,t i,j 表示从该地铁站的站厅走到第 i 条线
路的站台需要的时间。
输入的第 r + n + 2 (1 ≤ r ≤ q) 行包含两个正整数 x r , y r ,分别表示第 r 个出行计
划的起点和终点所在的地铁站编号。
*/
#include "bits/stdc++.h"
#define int long long
#define pii pair<int, int>
using namespace std;
int c, n, m, d, q;
int w[500005], vis[500005], dis[505][500005];
vector<pair<int, int>> e[600005];
void dijkstra(int st)
{
	priority_queue<pii, vector<pii>, greater<pii>> q;
	for(int i = 1;i <= m + n;i++)
	{
		dis[st][i] = 0x3f3f3f3f3f3f3f3f;
		vis[i] = 0;
	}
	dis[st][m + st] = 0;
	q.push({0, m + st});
	while(!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u] = 1;
		for(auto i : e[u])
		{
			int v = i.first, w = i.second;
			if(dis[st][v] > dis[st][u] + w)
			{
				dis[st][v] = dis[st][u] + w;
				q.push({dis[st][v], v});
			}
		}
	}
}
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			int a, t;
			cin >> a >> t;
			e[a].push_back({m + i, t});
			e[m + i].push_back({a, t});
		}
	}
	for(int i = 1;i <= n;i++)
	{
		dijkstra(i);
	}
	while(q--)
	{
		int x, y, ans = 0x3f3f3f3f3f3f3f3f;
		cin >> x >> y;
		for(int i = 1;i <= n;i++)
		{
			ans = min(ans, dis[i][x] + dis[i][y]);
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
