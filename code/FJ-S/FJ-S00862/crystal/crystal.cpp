#include<bits/stdc++.h>//100
using namespace std;
typedef long long inf;
inf n,m,a[500005],s[500005],sum[500005],li[500005],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(inf i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++)printf("%d ",a[i]);
	for(inf i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		s[i]=(a[i]-a[i-1])*(i-1);
		//printf("%d ",sum[i]);
	}
	for(inf i=1;i<=n;i++)
	{
		/*for(int j=i;j>=1;j--)
		{
			if(a[i]*(j-1)-sum[i-1]+sum[i-j]<=m)
			{
				ans=max(ans,j);
				break; 
			}
			//printf("%d ",a[i]*(j-1)-sum[i-1]+sum[i-j]);
		}*/
		inf l=1,r=i,mid=0;
		while(l<=r)
		{
			mid=l+(r-l)/2;
			if(a[i]*(mid-1)-sum[i-1]+sum[i-mid]<=m)l=mid+1;
			else r=mid-1;
		}
		//printf("%d %d %d\n",l,r,n);
		ans=max(ans,(l+r)/2);
	}
	/*int l=1,r=n,mid=0;
	while(l<=r)
	{
		mid=l+(r-l)/2;
		if(sum[mid]<=m)l=mid+1;
		else r=mid-1;
	}*/
	printf("%lld",ans);
	return 0;
}
