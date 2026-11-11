#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll c,n,k,ans,cnt,T;
ll head[N],to[N],nxt[N],a[N],f[N],dep[N];
bool vis[N],b[30][30],ddd[N];
void add(ll u,ll v)
{
	nxt[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
ll check(ll now)
{
	return  f[now]==now?now:(f[now]=check(f[now]));
}
void merge(ll u,ll v)
{
	f[check(u)]=check(v);
}
void dfs(ll now,ll fa)
{
	dep[now]=min(dep[now],dep[fa]+1);
	for(ll i=head[now];i;i=nxt[i])
	{
		ll v=to[i];
		if(v==fa||vis[v])continue;
		dfs(v,now);
	}
}
void ddfs(ll now)
{
	if(now==k+1)
	{
		ll t=0;
		for(ll i=1;i<=n;i++)f[i]=i,ddd[i]=0,dep[i]=INT_MAX;
		for(ll i=1;i<=k;i++)
		{
			for(ll j=i+1;j<=k;j++)
			{
				if(check(a[i])!=check(a[j])&&b[a[i]][a[j]])
				{
					merge(a[i],a[j]);
				}
			}
		}
		for(ll i=1;i<=k;i++)
		{
			if(!ddd[check(a[i])])
			{
				t++;
				ddd[check(a[i])]=1;
			}
		}
		if(t>2)return ;
		t=0;
		for(ll i=1;i<=k;i++)
		{
			dep[a[i]]=0;
			dfs(a[i],0);
		}
		for(ll i=1;i<=n;i++)t=max(t,dep[i]);
		ans=min(t,ans);
		return ;
	}
	for(ll i=1;i<=n;i++)
	{
		if(vis[i])continue;
		a[now]=i;
		vis[i]=1;
		ddfs(now+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--)
	{
		ans=INT_MAX;
		scanf("%lld%lld",&n,&k);
		for(ll i=1;i<n;i++)
		{
			ll u,v;
			scanf("%lld%lld",&u,&v);
			b[u][v]=b[v][u]=1;
			add(u,v),add(v,u);
		}
		ddfs(1);
		for(ll i=1;i<=20;i++)
		{
			for(ll j=1;j<=20;j++)b[i][j]=0;
			head[i]=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
