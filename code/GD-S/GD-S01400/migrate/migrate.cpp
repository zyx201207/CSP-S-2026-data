#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,rd,t,x[2000010],d[2000010],sum,v[2000010],cnt;
vector<ll>G[2000010];
void check(ll st)
{
	memset(d,0x3f3f3f3f,sizeof d);d[st]=0;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
	memset(v,0,sizeof v);
	q.push({0,st});
	while(q.size())
	{
		ll x=q.top().second;q.pop();
		if(v[x])continue;
		v[x]=1;
		for(ll y:G[x])
		{
			if(d[y]>d[x]+1)
			{
				d[y]=d[x]+1;
				q.push({d[y],y});
			}
		}
	}
}
void dfs(ll x,ll ed)
{
	if(cnt>2)return;
	if(x>ed)return;
	if(x==ed)
	{
		if(sum==d[ed])cnt++;
		return;
	}
	for(ll y:G[x])
	{
		sum++;
		dfs(y,ed);
		sum--;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&rd);
		for(ll i=1;i<=n;i++)scanf("%lld",&x[i]),G[i].clear();
		ll ans=0;
		for(ll i=1;i<=n;i++)for(ll j=i+1;j<=n;j++)
		{
			if(x[j]-x[i]<=rd)G[i].emplace_back(j);
			else break;
		}
		for(ll i=1;i<=n;i++)
		{
			check(i);
			for(ll j=i+1;j<=n;j++)
			{
				cnt=0;
				dfs(i,j);
				if(cnt==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
