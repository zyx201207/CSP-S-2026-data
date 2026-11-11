#include<bits/stdc++.h>
typedef long long ll;
const ll maxn=500,maxm=5e5,inf=1e18;
using namespace std;

ll read()
{
	ll x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')y=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*y;
}

struct node
{
	int v,w,nxt;
}e[maxm+4];
int head[maxn+5],tote;
void add(int u,int v,int w)
{
	e[++tote]={v,w,head[u]};
	head[u]=tote;
}
int n,m,q;
ll a[maxm+65];
ll d[maxn+5][maxn+5];
vector<pair<int,ll> >g[maxm+5];// ind w
void dijkstra(int s,ll *dis){
	for(int i=1;i<=n;++i)dis[i]=inf;
	dis[s]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int> > ,greater<pair<ll,int> > >q;
	q.push({dis[s],s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w)dis[v]=dis[u]+1ll*w,q.push({dis[v],v});
		}
	}
}

void solve()
{
	int _ttt,ttt2;
	_ttt=read();n=read();m=read();ttt2=read();q=read();
	for(int i=1;i<=m;++i)a[i]=read();
	for(int i=1;i<=n;++i)
	{
		int k,w,v;
		k=read();
		for(int j=1;j<=k;++j)
		{
			v=read(),w=read();
			for(int l=0;l<g[v].size();++l)
			{
				ll vv=g[v][l].first,ww=g[v][l].second;
				add(i,vv,w+ww);
				add(vv,i,w+ww);
			}
			g[v].push_back({i,w});
		}		
	}
	for(int i=1;i<=n;++i)dijkstra(i,d[i]);
	while(q--)
	{
		int u,v;
		ll ans=2e18;
		u=read(),v=read();
		for(int i=0;i<g[u].size();++i)
		{
			ll v1=g[u][i].first,w1=g[u][i].second;
			for(int j=0;j<g[v].size();++j)
			{
				ll v2=g[v][j].first,w2=g[v][j].second;
				ans=min(ans,d[v1][v2]+w1+w2+a[u]+a[v]);
			}
		}
		printf("%lld\n",ans);
	}
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int _=1;
	while(_--)solve();
	return 0;
}

