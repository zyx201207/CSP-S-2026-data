#include <bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
long long n,m,t,sum,ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++)
	{
		t=m;
		sum=1;
		for(long long j=i-1;j>=1;j--)
		{
			if(b[i] - b[j] <= t)
			{
				t-=(b[i] - b[j]);
				sum++;
			}
			else break;
		}
		if(ans < sum) ans=sum;
	}
	printf("%lld",ans);
	return 0;
}
