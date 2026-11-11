#include <bits/stdc++.h>
using namespace std;
int c,t,a[200005],dp[5005][5005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	int n,d;
	while(t--)
	{
		int ans=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i+3<=n;i++)
			if(a[i+1]-a[i]<=d&&a[i+2]-a[i]<=d&&a[i+3]-a[i]>d)
				dp[i][i+3]=1;
		for(int k=3;k<n;k++)
			for(int i=1,j=i+k;j<=n;i++)
				if(dp[i][j]&&a[j+1]-a[j]<=d&&a[j+2]-a[j]>d&&a[j+1]-a[j-1]>d)
					dp[i][j+1]=1;
		for(int i=1;i<=n-3;i++)
			for(int j=i+3;j<=n;j++)
				ans+=dp[i][j];
		printf("%d\n",ans);
	}
	return 0;
}
