#include <bits/stdc++.h>
using namespace std;
long long n,m,sum,a[500005];
bool cmp(long long x,long long y)
{
	return x > y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	bool f1 = 1,f2 = 1;
	for(long long i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
	}
	long long cha = a[2] - a[1];
	for(long long i = 1;i < n;i++)
	{
		if(a[i] != a[i + 1] - 1)
		{
			f1 = 0;
			printf("%lld 1 ",a[i]);
			printf("%lld\n",a[i + 1]);
		}
		else if(a[i + 1] - a[i] != cha)
		{
			f2 = 0;
			printf("%lld 2 ",a[i]);
			printf("%lld ",a[i + 1]);
			printf("%lld\n",cha);
		}
	}
	if(f1)
	{
		long long i = 1;
		while(m >= 0)
		{
			m -= i;
			i++;
			if(m >= 0)
			{
				sum++;
			}
		}
		printf("%lld",sum);
		return 0;
	}
	if(f2)
	{
		while(m >= 0)
		{
			m -= abs(cha);
			if(m >= 0)
			{
				sum++;
			}
		}
		printf("%lld",sum);
		return 0;
	}
	sort(a + 1,a + n + 1,cmp);
	for(int i = 2;i <= n;i++)
	{
		long long cnt = m,ans = 0;
		for(int j = i;j <= n;j++)
		{
			long long c = a[i] - a[j];
			if(c <= cnt)
			{
				ans++;
				cnt -= c;
			}
		}
		sum = max(sum,ans);
	}
	printf("%lld",sum);
	return 0;
}
