#include<bits/stdc++.h>
using namespace std;
struct road
{
	int x,sum;
};
int c,t,x[2000020],ans;
road dp[5020][5020];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
				dp[i][j].x=1e9;
		}
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j-1;x[j]-x[k]<=d and k>=i;k--)
				{
					if(dp[i][j].x>=dp[i][k].x+1)
					{
						if(dp[i][j].x==dp[i][k].x+1)
							dp[i][j].sum++;
						else
						{
							dp[i][j].x=dp[i][k].x+1;
							dp[i][j].sum=1;
						}
					}
				}
			}
		}
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(dp[i][j].sum==2)
					ans++;
		cout<<ans<<endl;
	}
	return 0;
}
