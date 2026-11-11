#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	long long flag=0;
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=a[2]-a[1])
		{
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		long long num=a[2]-a[1];
		long long id=0;
		for(long long i=n-1;i>=1;i--)
		{
			id=i;
			if((a[n]-a[i]+num)*(n-i)/2>m)
			{
				id++;
				break;
			}
		}
		printf("%lld",n-id+1);
		return 0;
	}
	long long ans=0;
	for(long long i=n;i>=1;i--)
	{
		while(a[i]==a[i+1])i--;
		if(i<=ans)break;
		long long ret=0;
		long long id=i;
		for(long long j=i-1;j>=1;j--)
		{
			if(ret+a[i]-a[j]>m)
			{
				break;
			}
			ret+=a[i]-a[j];
			id=j;
		}
		ans=max(ans,i-id+1);
	}
//	for(long long i=1;i<=n;i++)
//	{
//		while(a[i+1]==a[i])i++;
//		long long l=1,r=i;
//		long long ret=0;
//		while(l<=r)
//		{
//			long long mid=(l+r)/2;
//			if(sum[i]-sum[mid-1]<=m)
//			{
//				ret=i-mid+1;
//				r=mid-1;
//			}
//			else
//			{
//				l=mid+1;
//			}
//		}
//		ans=max(ans,ret);
//	}
	printf("%lld",ans);
	return 0;
}
