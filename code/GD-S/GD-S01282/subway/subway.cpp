#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=5e3+10,inf=1e9;
struct st
{
	ll v,w,l;
	bool operator < (const st &X) const
	{
		return w>X.w;
	}
};
struct node
{
	ll v,num;
};
vector<st> g[N];
vector<node> que[N];
ll n,m,ans[N],a[M][M],pre[N],t[M][M],zt[M][M],d,q,c,w[N],dis[2*N];
void dijkstra(ll s)
{
	priority_queue<st> q;
	dis[s+m]=0;
	q.push({s+m,0,0});
//	cout<<zt[s+m][1]<<endl;
	while(!q.empty())
	{
		ll u=q.top().v,pl=q.top().l;
		q.pop();
		for(auto c:g[u])
		{
			ll v=c.v,w=c.w,nl=c.l;
			if(pl==nl)
			{
				if(dis[v]>dis[u]+w)
				{
					dis[v]=dis[u]+w;
//					pre[v]=u;
					q.push({v,dis[v],nl});
				}
			}
			else if(pl!=nl&&pl!=0)
			{
				if(dis[v]>dis[u]+w+zt[u][pl]+zt[u+m][nl])
				{
					dis[v]=dis[u]+w+zt[u][pl]+zt[u+m][nl];
//					pre[v]=u;
					q.push({v,dis[v],nl});
				}
			}
			else if(pl==0)
			{
				if(dis[v]>dis[u]+w+zt[u][nl])
				{
					dis[v]=dis[u]+w+zt[u][nl];
					q.push({v,dis[v],nl});
				}
			}
		}
	}
	for(auto qu:que[s])
	{
		ll v=qu.v,num=qu.num;
		ans[num]=dis[v+m]+w[s]+w[v];
//		cout<<w[s]<<' '<<w[v]<<' '<<dis[v+m]<<endl;
//		cout<<dis[v+m]<<' ';
	}
//	cout<<endl;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j];
			if(j>1)
			{
				g[a[i][j-1]].push_back({a[i][j],0,i});
				g[a[i][j]].push_back({a[i][j-1],0,i});				
			}
			cin>>t[i][j];
			g[a[i][j]].push_back({a[i][j]+m,t[i][j],i});				
			g[a[i][j]+m].push_back({a[i][j],t[i][j],i});
			zt[a[i][j]][i]=t[i][j];
			zt[a[i][j]+m][i]=t[i][j];				
		}
	}
	ll cntq=0;
	while(q--)
	{
		ll s,t;
		cin>>s>>t;
		que[s].push_back({t,++cntq});
	}
	for(int i=1;i<=m;i++)
	{
		if(que[i].size()) 
		{
			for(int i=1;i<=2*m;i++)
			{
				dis[i]=inf;
			}
			dijkstra(i);
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(auto c:g[i])
//		{
//			cout<<c.v<<','<<c.w<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=cntq;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}

