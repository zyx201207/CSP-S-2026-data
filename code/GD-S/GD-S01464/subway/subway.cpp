#include <bits/stdc++.h>
using namespace std;

struct node
{
	int v,w;
};
const int N = 505,M = 500005;
int k[N],g[N],b[N][M],cnt,cc[M][N],dd[N],dis[M];
int c,n,m,d,q;
vector <node> e[M];
priority_queue <node> q;
void dij(int s)
{
	while (!q.empty()) q.pop();
	for (int i = 1;i <= m;i++) dis[i] = 1e9;
	dis[s] = 0;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	// 地铁线路数n 地铁站数m 每个地铁站最多被d条线路经过 出行计划数q
	// i为地铁站编号 j为地铁线路编号 
	// 口i 厅i + m 台cc[i][j] 虚线dd[j]
	cin >> c >> n >> m >> d >> q;
	cnt = m;
	for (int i = 1;i <= m;i++) 
	{
		int x;
		cin >> x;
		e[i].push_back({++cnt,x});
		e[cnt].push_back({i,x});
	}// 连口厅 
	for (int j = 1;j <= n;j++)
	{
		cin >> k[j];
		g[j + 1] = g[j] + k[j];
		for (int w = 1;w <= k[j];w++)
		{
			int x,t;
			cin >> x >> t;
			b[j][w] = x;
			e[++cnt].push_back({x + m,t});
			e[x + m].push_back({cnt,t});
			cc[x][j] = cnt;
		}
	}// 连厅台 
	for (int j = 1;j <= n;j++)
	{
		cnt++,dd[j] = cnt;
		for (int w = 1;w <= k[j];w++)
		{
			int x = b[j][w];
			e[cc[x][j]].push_back({cnt,0});
			e[cnt].push_back({cc[x][j],0});
		}
	}// 连台虚线 
	for (int i = 1;i <= q;i++)
	{
		int x,y;
		cin >> x >> y;
		dij(x);
		cout << x + y + d + n + q << endl;
	}
	return 0;
}
