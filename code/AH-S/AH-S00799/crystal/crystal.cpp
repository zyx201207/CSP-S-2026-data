#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],sum[500001],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	bool f=true;
	long long k=abs(a[2]-a[1]);
	for(int i=2;i<n;i++)
	{
		if(a[i+1]-a[i]!=k)
		{
			f=false;
			break;
		}
	}
	if(f==true)
	{
		long long p=m/k,cnt=0,ans=0;
		for(long long i=1;i<n;i++)
		{
			cnt+=i;
			if(cnt<=p)ans=i;
			else break;
		}
		ans++;
		printf("%lld",ans);
	}
	else
	{
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		sort(a+1,a+n+1);
		ans=0;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i;j>=1;j--)
			{
				long long u=a[i]*(i-j)-sum[i-1]+sum[j-1];
				if(u>m)break;
				ans=max(ans,i-j+1);
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
