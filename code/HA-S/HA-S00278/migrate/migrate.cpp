#include <bits/stdc++.h>
using namespace std;
long long x[2000001],m[2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,a=0,b=0;
	scanf("%lld",&c);
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
	{
		long long n,d,sum=0;
		scanf("%lld",&n);
		scanf("%lld",&d);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&x[j]);
		}
		for(int j=1;j<n;j++)
		{
			for(int k=n;k>j;k--)
			{
				int p=x[j];
				while(p<x[k])
				{
					if(x[j]+2<=x[k])
					{
						a++;
						p+=2;
					}
					else if(x[j]+2>x[k])
					{
						b++;
						p+=1;
					}
				}
			}
			if(a!=0&&b!=0)
			{
				sum++;
				a=0;
				b=0;
			}
		}
		m[i]=sum-1;
	}
	for(int i=1;i<=t;i++)
	{
		printf("%lld",m[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
