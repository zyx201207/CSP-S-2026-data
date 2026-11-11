#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500+10,M=5e5+10;
const ll inf=1e17;
ll c,n,m,d,q;
ll w[M],mp[N][N];
ll head[M],to[M],co[M],nxt[M],tot;
void addedge(ll u,ll v,ll w)
{
	tot++;
	nxt[tot]=head[u];
	to[tot]=v;
	co[tot]=w;
	head[u]=tot;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
		cin>>w[i];
	for(ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++)
		{
			ll ka,kt;
			cin>>ka>>kt;
			addedge(ka,i,kt);
		}
	}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			mp[i][j]=inf;
	for(ll i=1;i<=n;i++)
		mp[i][i]=0;
	for(ll i=1;i<=m;i++)
	{
		for(ll j=head[i];j;j=nxt[j])
		{
			for(ll k=head[i];k;k=nxt[k])
			{
				//cerr<<"makeedge "<<j<<" "<<k<<" "<<co[j]+co[k]<<endl;
				mp[to[j]][to[k]]=mp[to[k]][to[j]]=min(mp[to[j]][to[k]],co[j]+co[k]);
			}
		}
	}
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	/*
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
			cerr<<mp[i][j]<<" ";
		cerr<<endl;
	}
	*/
	for(ll i=1;i<=q;i++)
	{
		ll x,y;
		cin>>x>>y;
		ll ans=inf;
		for(ll ss=head[x];ss;ss=nxt[ss])
		{
			for(ll ee=head[y];ee;ee=nxt[ee])
			{
				ans=min(ans,mp[to[ss]][to[ee]]+co[ss]+co[ee]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
