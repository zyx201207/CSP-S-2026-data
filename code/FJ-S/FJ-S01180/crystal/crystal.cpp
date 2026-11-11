#include<iostream>
#include<algorithm>
using namespace std;
int n,m,ans;
long long a[500005],sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		int l=0,r=i;
		while(l+1!=r)
		{
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m)
				r=mid;
			else
				l=mid;
		}
		ans=max(ans,i-r+1);	
	}	
	printf("%d",ans);
	return 0;
}
