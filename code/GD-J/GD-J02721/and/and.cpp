#include <bits/stdc++.h>
using namespace std;
int n,m,a[200001],dp[200001],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n-m+1;i++)
	{
		dp[1]=a[i];
		for (int j=i+1;j<=n;j++)
			for (int k=2;k<=m;k++)
				dp[k]=max(dp[k],dp[k-1]&a[j]);
		ans=max(ans,dp[m]);
	}
	printf("%d",ans);
}
