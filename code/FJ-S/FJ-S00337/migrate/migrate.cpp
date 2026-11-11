#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[2000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	scanf("%lld%lld",&C,&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(C==11||C==12)
		{
			int k=m/(a[2]-a[1]),h=0;
			int g=(n-1)/k,l=(n-1)%k;
			g--;
			if(g<0)
			{
				printf("0\n");
				continue;
			}
			int f=g;
			while(f)
			{
				h+=(n-(f+1)*m+1+(m-2))*(f*(m-1));
				f--;
			}
			if(l!=0)
			{
				h+=(g+1)*((1+l)*l/2);
			}
			printf("%lld\n",h-1);
		}
	}
	return 0;
}
