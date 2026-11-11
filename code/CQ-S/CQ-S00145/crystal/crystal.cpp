#include<bits/stdc++.h>
using namespace std;
int n,ans,dp[500002];
long long m,a[500002];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=dp[i-1]*(a[i]-a[i-1]),dp[i]=dp[i-1]+1;
		if(cnt>m)
		{
			while(cnt>m&&dp[i]>1)
			{
				int j=i-dp[i]+1;
				cnt-=a[i]-a[j];
				dp[i]--;
			}
			if(dp[i]==1) cnt=0;
		}
		ans=max(ans,dp[i]);
		//printf("%lld %lld %lld\n",i,dp[i],cnt);
	}
	printf("%d",ans);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

¹Ø×¢ Hicka_stone ×¿À­£¡ 
*/
