#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d,a[2000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		int ans=0;
		for(int i=4;i<=n;i+=2)
		{
			if((a[2]-a[1])*(i-1)<=d)
			{
				ans+=n-i;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

//luogu£ºcy950469 Çó¹Ø
