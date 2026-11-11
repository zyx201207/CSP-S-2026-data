#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500015],c[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				b[i]+=a[i]-a[j];
			}
		}
		b[n+1]=10000000000000;
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			if((b[i]<=m)&&(m<=b[i+1]))
			{
				maxx=i;
			}
			//printf("%lld ",b[i]);
		}
		if(maxx==1) printf("0");
		else printf("%d",maxx);
		return 0;
	}
	bool f=0,ff=0;
	long long x=a[2]-a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=1) f=1;
		if(a[i]-a[i-1]!=x) ff=1;
	}
	if(!f)
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=a[i]+b[i-1];
		}
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			if((b[i-1]<=m)&&(m<=b[i]))
			{
				maxx=i;
			}
			//printf("%lld ",b[i]);
		}
		if(maxx==1) printf("0");
		else printf("%d",maxx);
		return 0;
	}
	if(!ff)
	{
		for(int i=1;i<=500010;i++)
		{
			b[i]=i+b[i-1];
		}
		for(int i=1;i<=n;i++)
		{
			c[i]=x*(b[i-1]);
		}
		int maxx=0;
		c[n+1]=10000000000000;
		for(int i=1;i<=n;i++)
		{
			if((c[i]<=m)&&(m<=c[i+1]))
			{
				maxx=i;
			}
			//printf("%lld ",c[i]);
		}
		if(maxx==1) printf("0");
		else printf("%d",maxx);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+((i-1)*(a[i]-a[i-1]));
		//printf("%lld ",b[i]);
	}
	b[n+1]=10000000000000000;
	long long maxx=0;
	for(long long i=1;i<=n;i++)
	{
		if((b[i]<=m)&&(m<=b[i+1]))
		{
			maxx=i;
		}
		printf("%lld %lld\n",i,b[i]);
	}
	if(maxx==1) printf("0"); 
	else printf("%lld",maxx);
	return 0;
}
