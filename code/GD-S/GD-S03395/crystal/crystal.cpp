#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500009];
long long c[500009];
long long sum,num,x;
bool A=1,B=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i = 1; i <= n; i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=i&&A)
		{
			A=0;
		}
		if(B&&i >= 3 && a[i]-a[i-1] != a[i-1]-a[i-2])
		{
			B=0;
		}
	}
	if(A)
	{
		for(long long i = 1; i < n; i++)
		{
			if((i+(i*i))/2<=m && ((i+1)+((i+1)*(i+1)))/2>m)
			{
//				cout << i;
				printf("%lld",i);
				return 0;
			}
		}
//		cout << n;
		printf("%lld",n);
	}
	if(B)
	{
		for(long long i = 1; i<n; i++)
		{
			if(((a[1]+a[i])*i)/2<=m && ((a[1]+a[i+1])*(i+1))/2>m)
			{
//				cout << i;
				printf("%lld",i);
				return 0;
			}
		}
//		cout << n;
		printf("%lld",n);
	}
	sort(a+1,a+n+1);
	for(long long i = 1; i <= n; i++)
	{
		c[i]=a[i+1]-a[i];
	}
	for(long long i = 1; i < n; i++)
	{
		num = c[i];
		x = i;
		while(num+(x-i+1)*c[x+1]+c[x+1] <= m && x < n)
		{
			if(c[x+1] != 0)
			{
				num = num+(x-i+1)*c[x+1]+c[x+1];
			}
			x++;
		}
		sum=max(sum,x-i+2);
	}
	printf("%lld",sum);
	return 0;
}
