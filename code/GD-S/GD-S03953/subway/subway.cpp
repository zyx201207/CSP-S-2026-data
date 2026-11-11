#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=500501;
int c,n,m,t,q,k,w[N],x[100001],y[100001],p[200001],idx,h[N];
vector<ll> d[501];
bool vis[N];
ll dis[N];
struct node{
	int v,nxt,w;
}e[N<<1];
void dij(int s)
{
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=h[u]; i; i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w)dis[v]=dis[u]+w,q.push({dis[v],v});
		}
	}
	for(int i=1; i<=k; i++)d[s-m][i]=dis[p[i]];
}
void bfs(int s)
{
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	dis[s]=0,vis[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=h[u]; i; i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w;
			if(!vis[v])vis[v]=1,dis[v]=dis[u]+w,q.push(v);
		}
	}
	for(int i=1; i<=k; i++)d[s-m][i]=dis[p[i]];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>t>>q;
	for(int i=1; i<=m; i++)cin>>w[i];
	for(int i=1,k; i<=n; i++)
	{
		cin>>k;
		for(int j=1,x,y; j<=k; j++)
		{
			cin>>x>>y;
			e[++idx]={x,h[m+i],y},h[m+i]=idx;
			e[++idx]={m+i,h[x],y},h[x]=idx;
		}
	}
	for(int i=1; i<=q; i++)cin>>x[i]>>y[i],p[++k]=x[i],p[++k]=y[i];
	sort(p+1,p+k+1);
	k=unique(p+1,p+k+1)-p-1;
	for(int i=1; i<=n; i++)
	{
		d[i].resize(k+1);
		if(c>=16&&c<=19)bfs(i+m);
		else dij(i+m);
	}
	for(int i=1; i<=q; i++)
	{
		int u=lower_bound(p+1,p+k+1,x[i])-p,v=lower_bound(p+1,p+k+1,y[i])-p;
		ll ans=1e18;
		for(int j=1; j<=n; j++)ans=min(ans,d[j][u]+d[j][v]);
		cout<<ans+w[x[i]]+w[y[i]]<<'\n';
	}
	return 0;
}
