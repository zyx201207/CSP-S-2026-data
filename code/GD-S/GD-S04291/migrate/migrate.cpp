#include<bits/stdc++.h>
#define ll long long
#define N 30050000
using namespace std;

const ll INF=1e18;

struct edge
{
	ll to,next,w;
}e[N];
ll head[N],tot=0;

ll c,T,ans;
ll n,d;
ll a[N];
ll dis[N],cnt[N];

void build(ll u,ll v)
{
	e[++tot]=(edge){v,head[u]};
	head[u]=tot;
}

void bfs(ll st)
{
	dis[st]=0;
	cnt[st]=1;
	for(int u=st;u<=n;u++)
	{
		if(cnt[u]==2) ans++;
		for(int i=head[u];i;i=e[i].next)
		{
			ll v=e[i].to;
			if(dis[v]==dis[u]+1) 
			{
				cnt[v]+=cnt[u];
			}
			else if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
			}
		}
	}	
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		tot=0;
		memset(head,0,sizeof(head));
		memset(e,0,sizeof(e));
		cin>>n>>d;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d) build(i,j);
				else break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cnt[j]=0;
				dis[j]=INF;
			}
			bfs(i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
