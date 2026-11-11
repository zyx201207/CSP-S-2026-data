#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+9;
ll id,Q;
ll n,d,a[N];
ll cut[N],tot;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&id,&Q);
	while(Q--)
	{
		scanf("%lld%lld",&n,&d);
		bool sub11=1;
		for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
		ll c=a[2]-a[1];
		for(int i=3;i<=n;i++)
		if(c!=a[i]-a[i-1])sub11=0;
		ll ans=0;
		if(sub11)
		{
			if(d<2*c)puts("0");
			else if(n*c<=d)puts("0");
			else printf("%lld\n",n-d/c-(d/c-1));
			continue;
		}
	}
	return 0;
}
