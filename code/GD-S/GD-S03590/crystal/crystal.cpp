#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int n,m;
int a[500005],s[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,res=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if((i-mid+1)*a[i]-s[i]+s[mid-1]<=m)
			{
				res=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1); 
	}
	printf("%lld",ans);
	return 0;
}
