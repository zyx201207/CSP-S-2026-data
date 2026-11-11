#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll n,m,c,d,ans,cnt,T;
ll a[N],head[N],to[N],nxt[N],dis[N],sum[N];
bool vis[N];
struct node
{
	ll n,w;
	bool operator<(const node &a)const
	{
		return a.w<w;
	}
};
priority_queue<node> b;
void add(ll u,ll v)
{
	nxt[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
ll dij(ll now)
{
	ll t=0;
	for(ll i=1;i<=n;i++) dis[i]=INT_MAX,sum[i]=vis[i]=0;
	dis[now]=0,sum[now]=1;
	b.push({now,0});
	while(!b.empty())
	{
		ll u=b.top().n;
		b.pop();
		if(vis[u])continue;
		vis[u]=1;	
		for(ll i=head[u];i;i=nxt[i])
		{
			ll v=to[i];
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				sum[v]=sum[u];
				b.push({v,dis[v]});
			}
			else if(dis[v]==dis[u]+1) sum[v]+=sum[u];
		}
	}
	for(ll i=1;i<=n;i++) if(sum[i]==2)t++;
	return t;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--)
	{
		cnt=ans=0;
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i-1;j;j--)
			{
				if(a[i]-a[j]<=d)add(i,j),add(j,i);
				else break;
			}
		}
		for(ll i=1;i<=n;i++) ans+=dij(i);
		printf("%lld\n",ans/2);
		for(ll i=1;i<=n;i++) head[i]=0;
	}
	return 0;
}
