#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e6+10;
const ll M=3050;
ll c,t; 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ll n,d;
		ll a[N]={};
		cin>>n>>d;
//		for(ll i=1;i<=n;i++)
//		{
//			scanf("%lld",&a[i]);
//		}
		ll cha=a[2]-a[1];
		if(d<cha)
		{
			cout<<0;
			continue;
		}
		else if(d==cha)
		{
			cout<<0;
			continue;
		}
		else if(cha*2<=d&&cha*3>d)
		{
			cout<<n-2;
			continue;
		}
		else 
		{
			cout<<0;
			continue;
		}
	}
	return 0;
}
