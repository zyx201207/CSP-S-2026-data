#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500510
#define pii pair<int,int>
int c,n,m,d,Q;
int dis[N];
int w[N];
bool vis[N];
struct edge
{
	int to,val;
};
vector<edge> a[N];
void add(int x,int y,int v)
{
	a[x].push_back((edge){y,v});
	a[y].push_back((edge){x,v});
}
void Dij(int r)
{
	priority_queue<pii> q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[r]=0;
	q.push(make_pair(0,r));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])	continue;
		vis[u]=true;
		for(int i=0;i<(int)a[u].size();i++)
		{
			int v=a[u][i].to;
			int val=a[u][i].val;
			if(dis[u]+val<dis[v])
			{
				dis[v]=dis[u]+val;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}	
signed main()
{
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int cnt;
		cin>>cnt;
		while(cnt--)
		{
			int x,v;
			cin>>x>>v;
			add(x,i+m+1,v);
		}
	}
	while(Q--)
	{
		int f,g;
		cin>>f>>g;
		int ans=w[f]+w[g];
		Dij(f);
		ans+=dis[g];
		cout<<ans<<endl;
	}	
	return 0;
}

