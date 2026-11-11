//GZ-S00027 ½ªÔ£Î°
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int c,t;
int dp[505][505];
int b[505][505];
int ans;
int n,d;
int x[505];
void floydd()
{
	ans=0;
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++)
			dp[i][j]=INT_MAX;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(x[i]-x[j]<=d)
			{
				dp[i][j]=1;
				dp[j][i]=1;
				b[i][j]=1;
				b[j][i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=0;
		b[i][i]=1;
	}
	for(int y=1;y<=n;y++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dp[i][y]==INT_MAX||dp[y][j]==INT_MAX) continue;
				if(i==j||j==y||i==y) continue;
//				cout<<dp[i][j];
				if(dp[i][y]+dp[y][j]==dp[i][j]&&dp[i][j]<INT_MAX)
				{
					b[i][j]+=b[i][y]*b[y][j];
//					cout<<b[i][j]<<" "<<i<<" "<<j<<endl;
				}
				else if(dp[i][y]+dp[y][j]<dp[i][j])
				{
					b[i][j]=b[i][y]*b[y][j];
					dp[i][j]=dp[i][y]+dp[y][j];
				}
			}
		}
	}
//	cout<<b[1][4]<<" ";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)  continue;
//			cout<<b[i][j];
			if(b[i][j]==2) ans++;
		}
	}
}
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
			scanf("%lld",&x[i]);
		}
		floydd();
		printf("%lld\n",ans/2);
	}
	return 0;
}

