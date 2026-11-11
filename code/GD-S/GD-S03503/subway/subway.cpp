#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,Q;
int w[1000010],k[1000010],a[1010][1010],t[1010][1010];
int dis[100010];
bool vis[1010][1010];
struct node
{
	int x,y,t;	
};
struct node2
{
	int X,Y;	
};
vector<node> g[1010][1010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1 ; i <= m ; i ++) cin >> w[i];
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> k[i];
		for(int j = 1 ; j <= k[i] ; j ++) 
		{
			cin >> a[i][j] >> t[i][j];
			g[i][a[i][j-1]].push_back({i,a[i][j],t[i][j]});
			g[i][a[i][j]].push_back({i,a[i][j-1],t[i][j]});
			g[i][a[i][j]].push_back({i+1,a[i+1][j],t[i][j]+t[i+1][j]});
			g[i][a[i][j]].push_back({i-1,a[i-1][j],t[i][j]+t[i-1][j]});
		}
	}
	while(Q--)
	{
		int x1,y1;
		cin >> x1 >> y1;
		queue<node2> q;
		dis[x1] = w[x1];
		vis[1][x1] = true;
		q.push({1,x1});
		while(q.size() != 0)
		{
			int u = q.front().X,v = q.front().Y;
			q.pop();
			vis[u][v] = false;
			for(int i = 0 ; i < g[u][v].size() ; i ++)
			{
				int e = g[u][v][i].x , f = g[u][v][i].y,d = g[u][v][i].t;
				if(dis[v] > dis[f] + d)
				{
					dis[v] = dis[f] + d;
					if(!vis[e][f])
					{
						q.push({e,f});
						vis[e][f] = true;
					}
				}
			}
		}
		cout << dis[y1] << "\n";
	} 
}
