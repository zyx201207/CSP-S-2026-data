#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
int c,n,m,d,q;
int w[500005];
int a[500005];
int nd[50000005];
ll ans;
ll dis[50000005];
bool flag[50000005],vis[50000005];
int k[505];
vector<pair<int,int> > edges[1000005];
priority_queue<pair<ll,int> > pq;
void dijk(int x)
{
	fill(dis+1,dis+1+m*n,1e18);
	fill(vis+1,vis+1+m*n,0);
	pq.push(make_pair(0,x));
	dis[x]=0;
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<edges[u].size();i++)
		{
			int v=edges[u][i].first;
			ll w=edges[u][i].second;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				pq.push(make_pair(-1*dis[v],v));
			}
		}
	}
}
int main()
{
//	freopen("subway7.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cout<<(sizeof(nd)+sizeof(flag)+sizeof(edges)+sizeof(dis)+sizeof(vis))/1024/1024;//690MB
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int t;
			cin>>a[j]>>t;
			nd[a[j]+m*(i-1)]=t;
			flag[a[j]+m*(i-1)]=1;
		}
		for(int j=1;j<k[i];j++)
		{
			edges[a[j]+m*(i-1)].push_back(make_pair(a[j+1]+m*(i-1),0));
			edges[a[j+1]+m*(i-1)].push_back(make_pair(a[j]+m*(i-1),0));
		}
	}
	for(int i=1;i<=m;i++)//O(mn^2)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				int u=i+m*(j-1),v=i+m*(k-1);
				if(flag[u]&&flag[v])
				{
					edges[u].push_back(make_pair(v,nd[u]+nd[v]));
					edges[v].push_back(make_pair(u,nd[u]+nd[v]));
				}
			}
		}
	}
	while(q--)//O(qn(n*m+n))
	{
		int x,y;
		cin>>x>>y;
		ans=1e18;
		for(int i=1;i<=n;i++)
		{
			dijk(x+m*(i-1));
			ll s1=1e18;
			for(int j=1;j<=n;j++)
			{
				s1=min(dis[y+m*(j-1)]+nd[y+m*(j-1)]+nd[x+m*(i-1)],s1);
			}
			ans=min(ans,s1);
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
//maybe 32pts
