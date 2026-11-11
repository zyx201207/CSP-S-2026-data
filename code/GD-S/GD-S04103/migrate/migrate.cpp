#include<bits/stdc++.h>
typedef long long ll;
const ll N=2e6+5,inf=3e18+5;
using namespace std;
ll C,T,n,d,x[N];
ll idx=0,h[N<<1],e[N<<1],ne[N<<1],dis[N],cnt[N];
bool vis[N];
struct node {
	ll dis,tt;
};queue<node> q;
void add(ll a,ll b)
{
	e[++idx]=b;
	ne[idx]=h[a];
	h[a]=idx;
}
void bfs(ll x)
{
	q.push({0,x});
	fill(dis+1,dis+n+1,inf);
	dis[x]=0;
	cnt[x]=1;
	while(!q.empty())
	{
		ll u=q.front().tt;
		q.pop();
		if (vis[u])
		{
			continue;
		}
		vis[u]=true;
		for(ll i=h[u];i!=0;i=ne[i])
		{
			ll v=e[i];
			if (dis[v]==dis[u]+1)
			{
				cnt[v]++;
			}
			if (dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push({dis[v],v});
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&C,&T);
	while(T--)
	{
		scanf("%lld %lld",&n,&d);
		for(ll i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		x[n+1]=inf;
		for(ll i=1;i<=n;i++)
		{
			ll nxt=upper_bound(x+i,x+n+2,x[i]+d)-x-1;
			for(ll j=i+1;j<=nxt;j++)
			{
				add(i,j);
				add(j,i);
			}
		}
		ll ans=0;
		for(ll i=1;i<=n;i++)
		{
			bfs(i);
			for(ll j=i+1;j<=n;j++)
			{
				if (cnt[j]==2)
				{
					ans++;
				}
			}
			while(!q.empty())
			{
				q.pop();
			}
			for(ll j=1;j<=n;j++)
			{
				dis[j]=cnt[j]=0;
				vis[j]=false;
			}
		}
		printf("%lld\n",ans);
		fill(h,h+n+1,0);
		fill(e,e+idx+1,0);
		fill(ne,ne+idx+1,0);
		idx=0;
	}
	return 0;
}
