#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll k[500005],ans[500005];
struct node
{
	ll t,w;
}s[500005];
int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>s[i].w;
	for(ll i=1;i<=n;i++)
	{
		ll r;cin>>r;
		for(ll i=1;i<=r;i++)
		{
			cin>>k[i];
			cin>>s[k[i]].t;
		}
	}
	for(int i=1;i<=q;i++)
	{
		ll x,y;
		cin>>x>>y;
		ll ans=0;
		for(int i=1;i<=n;i++)ans[i]+=s[i].t+s[i].w;
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
	return 0;
}
