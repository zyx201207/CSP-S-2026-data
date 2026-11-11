#include<bits/stdc++.h>
using namespace std;
long long n,a[500005];
long long m,sum,ans1,ans;
long long minn=INT_MAX;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	sum/=n;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(minn<=0){
			sum=a[i-1];
			break;
		}
		minn=min(sum-a[i],minn);
		//printf("minn=%lld\n",minn);
	}
	//printf("sum=%lld\n"r,sum);
	for(long long i=n;i>=1;i--)
	{
		if(a[i]<=sum)
		{
			m-=sum-a[i];
			a[i]=sum;
			ans1++;
		}
		if(i==1&&m>=0)
		{
			sum+=1;
			i=n;
			ans=ans1;
			ans1=0;
		}
		//printf("m=%lld ans=%lld\n",m,ans);
	}
	printf("%lld",ans);
	return 0;
}
