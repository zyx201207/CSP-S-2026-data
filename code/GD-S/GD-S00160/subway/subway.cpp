#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,n,m,d,q,w[500005],a,t,x,y,k[505],ans,l[600005],aa,tt;
bool f[600005];
vector<pair<ll,ll> > e[600005];
void dfs(ll z,ll s)
{
	if(z==y){ans=min(ans,s);return ;}
	if(f[z]==1)return ;
	f[z]=1;
	for(int i=0;i<l[z];i++)
		dfs(e[z][i].first,s+e[z][i].second);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%lld",&a);
			scanf("%lld",&t);
			e[a].push_back({m+i,t}),l[a]++;
			e[m+i].push_back({a,t}),l[m+i]++;;
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&x,&y);
		memset(f,0,sizeof(f));
		ans=1e18;
		dfs(x,0);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
