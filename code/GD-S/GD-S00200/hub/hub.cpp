#include<bits/stdc++.h>
#define ll long long
#define pp pair<ll,ll>
using namespace std;
const int N=1e6+5;
ll c,T;
ll n,m;
struct abc
{
	ll zhi,id,vis2;
}deg[N];
bool cmp(abc x,abc y)
{
	if(x.vis2!=y.vis2)x.vis2>y.vis2;
	else return x.zhi>y.zhi;
}
bool cmp1(abc x,abc y)
{
	return x.id<y.id;
}
vector<ll>g[N];
ll vis1[N];
ll mi[N];
ll vis[N];
ll d[N];
ll vis2[N];
void dij(ll st)
{
	for(int i=1;i<=m;i++)
	{
		d[i]=INT_MAX; 
		vis[i]=0;
	}
	d[st]=0;
	priority_queue<pp,vector<pp>,greater<pp>>q;
	q.push({0,st});
	while(!q.empty())
	{
		ll u=q.top().second;
		q.pop();
		if(vis[u]==1)continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++)
		{
			ll v=g[u][i],w=1;
			if(d[u]+w<d[v])
			{
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			deg[i].zhi=0;
			deg[i].id=i;
			g[i].clear();
			vis1[i]=0;
			mi[i]=INT_MAX;
		}
		for(int i=1;i<n;i++)
		{
			ll u,v;
			cin>>u>>v;
			deg[u].zhi++;
			deg[v].zhi++;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++)vis2[i]=0;
		for(int i=1;i<=min(2ll,m);i++)
		{
			sort(deg+1,deg+1+n,cmp);
			ll u=deg[1].id;
			//cout<<u<<' ';
			sort(deg+1,deg+1+n,cmp1);
			for(int j=0;j<g[u].size();j++)
			{
				ll v=g[u][j];
				deg[v].zhi--;
			}
			deg[u].zhi=0;
			vis1[u]=1;
		}
		for(int i=3;i<=m;i++)
		{
			for(int j=1;j<=n;j++)deg[j].vis2=0;
			for(int j=1;j<=n;j++)
			{
				if(vis1[j]==1)
				{
					for(int k=0;k<g[j].size();k++)
					{
						deg[g[j][k]].vis2=1;
					}
				}
			}
			//for(int i=1;i<=n;i++)cout<<deg[i].vis<<" ";
			sort(deg+1,deg+1+n,cmp);
			ll u=deg[1].id;
			//cout<<deg[1].vis<<' ';
			//for(int i=1;i<=n;i++)cout<<deg[i].vis2<<" ";
			sort(deg+1,deg+1+n,cmp1);
			for(int j=0;j<g[u].size();j++)
			{
				ll v=g[u][j];
				deg[v].zhi--;
			}
			deg[u].zhi=0;
			vis1[u]=1;
		}
		/*for(int i=1;i<=n;i++)cout<<vis[i]<<" ";
		cout<<"\n";*/
		for(int i=1;i<=n;i++)
		{
			if(vis1[i]==1)
			{
				dij(i);
				//cout<<i<<" ";
				for(int j=1;j<=n;j++)mi[j]=min(mi[j],d[j]);
			}
		}
		ll ma=0;
		for(int i=1;i<=n;i++)ma=max(ma,mi[i]);
		cout<<ma<<"\n";
	}

	return 0;
}

