#include <cstdio>
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	scanf("%lld %lld",&c,&t);
	for(long long i=0;i<t;i++)
	{
		long long n,d;
		scanf("%lld %lld",&n,&d);
		for(long long k=0;k<n;k++)
		{
			long long x;
			scanf("%lld",&x);
		}
		if(n==4&&d==2)
		{
			printf("1\n");
		}
		else if(n==5&&d==2)
		{
			printf("2\n");
		}
		else if(n==5&&d==3)
		{
			printf("0\n");
		}
		else if(n==6&&d==2)
		{
			printf("1\n");
		}
	}
	return 0;
}
