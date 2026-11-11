#include<bits/stdc++.h>
using namespace std;

struct node
{
	int t,v;
};

struct N
{
	int x;
	long long y;
	bool operator<(const N &a)const
	{
		return y>a.y;
	}
};

int c,n,m,d,q;
long long w[500005];
vector<node> g[600005];
long long dist[3000][3000];
int vis[20000];
priority_queue<N> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		int x=i+n;
		int t;
		cin>>t;
		for(int i=1;i<=t;i++)
		{
			int y,z;
			cin>>y>>z;
			g[x].push_back({y,z});
			g[y].push_back({x,z});
		}
	}
	n+=m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dist[i][j]=2147483647;
	while(q--)
	{
		for(int i=1;i<=n;i++)vis[i]=0;
		int st,en;
		cin>>st>>en;
		if(dist[st][en]!=2147483647)
		{
			cout<<dist[st][en]+w[st]+w[en]<<endl;
			continue;
		}
		if(dist[en][st]!=2147483647)
		{
			cout<<dist[en][st]+w[st]+w[en]<<endl;
			continue;
		}
		pq.push({st,0});
		dist[st][st]=0;
		while(!pq.empty())
		{
			N tmp=pq.top();pq.pop();
			int u=tmp.x;
//			dist[u][st]=dist[st][u];
			vis[u]=1;
			for(node i:g[u])
			{
				if(dist[st][u]+i.v<dist[st][i.t] && !vis[i.t])
				{
					dist[st][i.t]=dist[st][u]+i.v;
					pq.push({i.t,dist[st][i.t]});
				}
			}
		}
//		for(int i=1;i<=n;i++)cout<<dist[st][i]<<" ";
//		cout<<endl;
		cout<<dist[st][en]+w[st]+w[en]<<endl;
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
