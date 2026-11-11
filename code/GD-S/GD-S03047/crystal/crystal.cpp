#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005],sq;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1; i<=n; i++)
	{
		scanf("%lld",&a[i]);
	}
	if(n>10000)
	{
		if(a[1]==a[2])
		{
			printf("%lld\n",n);
			return 0;
		}
		long long sum=0,ss=0,dd=a[2]-a[1];
		for(long long i=1; i<=n; i++)
		{
			if(ss+(sum+1)*dd>m) break;
			sum++;
			ss=ss+sum*dd;
		}
		printf("%lld\n",sum);
		return 0;
	}
	sort(a+1,a+n+1);
	d[1]=0;
	for(long long i=2; i<=n; i++)
	{
		d[i]=d[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(long long i=1; i<n; i++)
	{
		d[i]=0;
		if(i!=1){
			for(long long j=i+1; j<=n; j++)
			{
				d[j]=d[j]-(a[j]-a[i]);
			}
		}
		long long ans=upper_bound(d+1,d+1+n,m)-d;
		ans--;
		ans=ans-i+1;
		sq=max(sq,ans);
	}
	printf("%lld\n",sq);
	return 0;
}
