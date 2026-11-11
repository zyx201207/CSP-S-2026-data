#include <bits/stdc++.h>
using namespace std;
int c,q,n,d,dp[5005][5005],a[5005],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q--)
	{
		memset(dp,0,sizeof dp);
		memset(a,0,sizeof a);
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<=n-1;i++)dp[i][i]=1;
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int x=a[j];
				for(int k=j-1;k>=i;k--)
				{
					if(x-a[k]>d)break;
					dp[i][j]+=dp[i][k];
				}
			}
		}
		for(int i=1;i<=n-1;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(dp[i][j]==2){
				ans++;break;}
			}
		printf("%d\n",0);
	}
	return 0;
}