#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,m,a[500005],ans=1,b[4];

inline void add(ll a)
{
	if(a>=1000000000000000000)
	{
		b[2]+=a/1000000000000000000;
		b[1]+=a%1000000000000000000;
	}
	else
	{
		b[1]+=a%1000000000000000000;
		if(b[1]>=1000000000000000000)
		{
			b[2]+=b[1]/1000000000000000000;
			b[1]=b[1]%1000000000000000000;
		}
	}
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;++i)
	{
		if(a[i]!=a[1])
		{
			break;
		}
		++ans;
	}
	if(ans==1) ans=0;
	for(ll i=2;i<=n;++i)
	{
		ll cachem=m,ansc=1;
		for(ll j=i-1;j>=1;--j)
		{
			ll cache=a[i]-a[j];
			if(cachem>=cache)
			{
				cachem-=cache;
				++ansc;
			}
			else
			{
				break;
			}
		}
		if(ansc==1) ansc=0;
		ans=max(ans,ansc);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
