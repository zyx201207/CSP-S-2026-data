#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sc cout
#define ull unsigned long long
ll w[500010],k,a[510][25000],t[510][25000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll c,n,m,d,q;
	ll k;
	ll x,y;
	ll ans=0;
	cin>>c>>n>>m>>d>>q;
	for(ll i=0;i<m;i++) cin>>w[i];
	for(ll i=0;i<n;i++) {
		cin>>k;
		for(ll j=0;j<k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	ll pd;
	for(ll i=0;i<q;i++)
	{
		cin>>x>>y;
		ans=w[x]+w[y];
		for(ll i=0;i<n;i++)
		{
			ans+=t[i][0]+t[i][1];
		}
		cout<<ans<<endl;
	}
	return 0;
}
