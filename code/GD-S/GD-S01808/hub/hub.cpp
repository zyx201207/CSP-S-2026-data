#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const ll MAXN=1e6+5;
ll c,t,n,k,dis[MAXN],ans;
bool used[MAXN],b[MAXN];
vector<ll> G[MAXN];
void bfs1(ll s)
{
	queue<ll> q;
	q.push(s);
	b[s]=true;
	while(q.size())
	{
		ll t=q.front();
		q.pop();
		for(auto u:G[t])
			if(used[u]&&!b[u])
			{
				q.push(u);
				b[u]=true;
			}
	}
}
void bfs2(ll s)
{
	queue<ll> q;
	q.push(s);
	while(q.size())
	{
		ll t=q.front();
		q.pop();
		for(auto u:G[t])
			if(!used[u]&&dis[t]+1<dis[u])
			{
				dis[u]=dis[t]+1;
				q.push(u);
			}
	}
}
void work()
{
	ll cnt=0;
	memset(b,0,sizeof(b));
	for(ll i=1;i<=n;i++)
		if(used[i]&&!b[i])
		{
			bfs1(i),cnt++;
			if(cnt>2) return;
		}
	memset(dis,0x7f,sizeof(dis));
	for(ll i=1;i<=n;i++)
		if(used[i]) dis[i]=0;
	for(ll i=1;i<=n;i++)
		if(used[i]) bfs2(i);
	ll S=0;
	for(ll i=1;i<=n;i++)
		if(!used[i]) S=max(S,dis[i]);
	ans=min(ans,S);
}
void dfs(ll dep,ll sum)
{
	if(dep>n)
	{
		work();
		return;
	}
	if(n-dep+1>sum)
	{
		used[dep]=false;
		dfs(dep+1,sum);
	}
	if(sum)
	{
		used[dep]=true;
		dfs(dep+1,sum-1);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		for(ll i=1;i<=n;i++) G[i].clear();
		for(ll i=1;i<n;i++)
		{
			ll u,v;
			scanf("%lld%lld",&u,&v);
			G[u].pb(v);
			G[v].pb(u);
		}
		ans=1e16;
		dfs(1,k);
		printf("%lld\n",ans);
	}
	return 0;
}
