#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+7;
int c,t;
int n,d,a[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		int k=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]-a[1]<=d&&a[n]-a[i]<=d)
			{
				k=i;
				break;
			}
		}
		int j=k,ans=0;
		for(int i=1;i<=k;i++)
		{
			while(j<n&&a[j]-a[i]<=d)
			{
				j++;
			}
			if(j==k+2)
			{
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//const int inf=1e18+7;
//const int N=2e6+7;
//int c,t;
//int n,d;
//int a[N];
//int dp[N],g[N],s[N],h[N],sh[N];
//signed main()
//{
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
//	scanf("%lld%lld",&c,&t);
//	while(t--)
//	{
//		scanf("%lld%lld",&n,&d);
//		for(int i=1;i<=n;i++)
//		{
//			scanf("%lld",&a[i]);
//		}
//		int j=0,ans=0,rec=0;
//		a[j]=-inf;
//		for(int i=1;i<=n;i++)
//		{
//			while(a[i]-a[j]>d)
//			{
//				j++;
//				rec-=dp[j]*(i-j);
//			}
//			g[i]=j;
//			dp[i]=sh[i-1]-sh[g[i]-1]-rec;
//			for(int k=g[i]-1;k>0&&(i-g[i])>=2&&a[g[i]+2]-a[k]>d;k--)
//			{
//				dp[i]++;
//			}
//			s[i]=s[i-1]+dp[i];
//			h[i]=s[i]-s[g[i]-1];
//			sh[i]=sh[i-1]+h[i];
//			rec+=s[i]-s[g[i]-1];
//			ans+=dp[i];
//		}
//		printf("%lld\n",ans);
//		for(int i=1;i<=n;i++)
//		{
//			dp[i]=a[i]=0;
//		}
//	}
//	return 0;
//}
