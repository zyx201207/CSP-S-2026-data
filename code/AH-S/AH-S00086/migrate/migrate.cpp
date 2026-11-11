#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;cin>>c>>t;
	while(t--)
	{
		ll n,d;cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		ll cnt=0;
		for(int i=1;i<=n-3;i++)
		{
			if(a[i+3]-a[i]>d&&a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d)cnt++;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
