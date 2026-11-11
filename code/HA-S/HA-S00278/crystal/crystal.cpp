#include <bits/stdc++.h>
using namespace std;
long long a[500001],b[500001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	long long sum=1,t=0,k=m;
	for(long long i=n;i>1;i--)
	{
		for(long long j=i-1;j>=1;j--)
		{
			if(a[i]-a[j]<=k)
			{
				k=k-(a[i]-a[j]);
				sum++;
			}
			else
			{
				break;
			}
		}
		b[t]=sum;
		sum=1;
		k=m;
		t++;
	}
	sort(b,b+n);
	printf("%lld",b[n-1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
