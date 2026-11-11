#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using pll=pair<ll,ll>;
const ll N=5e2+2;
ll c,n,m,d,q,p,w[N];
vector<pll>v[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++)
	{
		ll k;cin>>k;
		for(ll j=1;j<=k;j++)
		{
			ll x,y;cin>>x>>y;
			v[i].push_back({x,y});
			p=y;
		}
	}
	while(q--)
	{
		ll x,y,ans=0;cin>>x>>y;
		ans+=w[x];ans+=w[y];
		ans+=v[1][x-1].second;
		ans+=v[1][y-1].second;
		cout<<ans<<endl;
	}
	return 0;
}
