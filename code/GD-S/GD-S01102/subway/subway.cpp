#include <bits/stdc++.h>

using namespace std;

#define int long long
#define PII pair<int,int>
#define f first
#define s second
int c,m,n,d,q,r[2005];
int dis[2005][2005];
vector<PII> edge[2005];
void dijk(int s)
{
	dis[s][s]=0;
	priority_queue<PII,vector<PII>,greater<PII>> pq;
	pq.push({0,s});
	
	while (!pq.empty())
	{
		int d=pq.top().f;
		int u=pq.top().s;
		
		pq.pop();
		if (d!=dis[s][u])
			continue;
			
		for (PII e:edge[u])
		{
			int v=e.f;
			int w=e.s;
			
			if (dis[s][v]>d+w)
			{
				dis[s][v]=d+w;
				pq.push({dis[s][v],v});
			}
		}
	}
}
vector<int> edges[2005];
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	dis[s][s]=0;
	
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		
		for (int v:edges[u])
		{
			if (dis[s][v]==-1)
			{
				dis[s][v]=dis[s][u]+1;
				q.push(v);
			}
		}
	}
}
void workB()
{
	int tt;
	for (int i=1;i<=m;++i)
	{
		int k;
		cin >> k ;
		
		for (int o=1;o<=k;++o)
		{
			int v,w;
			cin >> v >> w ;
			tt=w;
			edges[i+n].push_back(v);
			edges[v].push_back(i+n);
		}
	}
	
	memset (dis,-1,sizeof(dis));
	for (int i=1;i<=n;++i)
		bfs(i);

	while (q--)
	{
		int x,y;
		cin >> x >> y ;
		
		cout << dis[x][y]*tt+r[x]+r[y] << '\n' ;
	}
}
signed main ()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> c >> m >> n >> d >> q ;
	
	
	for (int i=1;i<=n;++i)
	{
		cin >> r[i] ;
	}
	
	if (c>=12&&c<=19)
	{
		workB();
		return 0;
	}
	for (int i=1;i<=m;++i)
	{
		int k;
		cin >> k ;
		
		for (int o=1;o<=k;++o)
		{
			int v,w;
			cin >> v >> w ;
			 
			edge[i+n].push_back({v,w});
			edge[v].push_back({i+n,w});
		}
	}
	
	memset (dis,0x3f,sizeof(dis));
	
	for (int i=1;i<=n;++i)
		dijk(i);

	while (q--)
	{
		int x,y;
		cin >> x >> y ;
		
		cout << dis[x][y]+r[x]+r[y] << '\n' ;
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
