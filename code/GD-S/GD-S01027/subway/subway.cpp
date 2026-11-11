#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int N = 510;
const int M = 1010;
int c,n,m,d,q;
int w[M],k[N],a[N][N],t[N][N],cnt[N][M];
struct sta{
	int id,w;
};
vector <sta> s[M];
struct edge{
	int lv,v,w;
};
vector <edge> G[N][M];
struct node{
	int lv,u,dis;
	bool operator > (const node &nd)const
	{
		return dis > nd.dis;
	}
};
priority_queue <node,vector <node>,greater <node>> pq;
bool vis[N][M];
int dis[N][M];
void dijk(int lv,int s)
{
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	while(!pq.empty())
		pq.pop();
	dis[lv][s] = 0;
	pq.push({lv,s,0});
	while(!pq.empty())
	{
		int u = pq.top().u,lev = pq.top().lv;
		pq.pop();
		if(vis[lev][u])
			continue;
		vis[lev][u] = true;
		for(auto ed : G[lev][u])
		{
			int lvv = ed.lv,v = ed.v,w = ed.w;
			if(dis[lvv][v] > dis[lev][u] + w)
			{
				dis[lvv][v] = dis[lev][u] + w;
				pq.push({lvv,v,dis[lvv][v]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
			s[a[i][j]].push_back({i,t[i][j]});
			cnt[i][a[i][j]] = t[i][j];
		}
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j < k[i];j++)
			for(int l = j + 1;l <= k[i];l++)
				G[i][a[i][j]].push_back({i,a[i][l],0}),
				G[i][a[i][l]].push_back({i,a[i][j],0});
	for(int i = 1;i <= m;i++)
	{
		for(auto u : s[i])
			for(auto v : s[i])
			{
				if(u.id == v.id)
					continue;
				G[u.id][i].push_back({v.id,i,u.w + v.w}),
				G[v.id][i].push_back({u.id,i,u.w + v.w});
			}
	}
	while(q--)
	{
		int x,y,ans = 2e9;
		cin >> x >> y;
		for(int i = 1;i <= n;i++)
		{
			int in = cnt[i][x];
			if(!in)
				continue;
			dijk(i,x);
			for(int j = 1;j <= n;j++)
			{
				int out = cnt[j][y];
				if(!out)
					continue;
				if(dis[j][y] + in + out < ans)
				{
//					cout << i  << ' ' << j << '\n';
					ans = min(ans,dis[j][y] + in + out);
				}
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
