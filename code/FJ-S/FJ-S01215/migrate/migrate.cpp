#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long n,d,a[N],ans;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(d<(a[2]-a[1])*2)
		{
			printf("0\n");
			continue;
		}
		long long lx=d/(a[2]-a[1])*2-1;
		ans=n-lx;
		if(ans<0) ans=0;
		printf("%lld\n",ans);
	}	
	
	return 0;
}

