#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pa pair<ll,ll>
#define fi first
#define se second
#define pb push_back
ll c,n,m,d,q;
ll w[600005],kk[1005];
ll dp[1005][1005];
ll des,zhi;
vector<pa > e[700005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for (ll i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	memset(dp,0x3f3f3f3f3f,sizeof(dp));
	for (ll i=1;i<=n;i++)
	{
		scanf("%lld",&kk[i]);
		for (ll j=1;j<=kk[i];j++)
		{
			scanf("%lld%lld",&des,&zhi);
			e[des].push_back(make_pair(i+m,zhi));
			e[i+m].push_back(make_pair(des,zhi));
		}
	}
	for (ll i=1;i<=m;i++)
		for (ll j=0;j<e[i].size();j++)
		{
			ll u=e[i][j].fi-m,wa=e[i][j].se;
			for (ll k=j+1;k<e[i].size();k++)
			{
				ll v=e[i][k].fi-m,wb=e[i][k].se;
				dp[u][v]=dp[v][u]=min(dp[u][v],wa+wb);
			}
		}
	for (ll i=1;i<=n;i++)
		dp[i][i]=0;
	for (ll k=1;k<=n;k++)
		for (ll i=1;i<=n;i++)
			for (ll j=1;j<=n;j++)
				dp[i][j]=dp[j][i]=min(min(dp[i][j],dp[j][i]),dp[i][k]+dp[k][j]);
	while (q--)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ll ans=LONG_LONG_MAX;
		for (ll i=0;i<e[x].size();i++)
			for (ll j=0;j<e[y].size();j++)
					ans=min(ans,e[x][i].se+e[y][j].se+dp[e[x][i].fi-m][e[y][j].fi-m]);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
	}

