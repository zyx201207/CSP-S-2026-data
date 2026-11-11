#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const int M=5005;
int c,t,n;
long long d,x[N],dp[M][M],dp1[M][M];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) 
			{
				dp[i][j]=0,dp1[i][j]=0;
				if(i==j) dp1[i][j]=1;
			}
		}
		for(int i=1;i<n;i++)
		{
			int t1=i;
			dp[i][t1]=0;
			for(int k=i+1;k<=n;k++)
			{
				if(x[k]-x[t1]<=d) dp[i][k]=dp[i][t1]+1;
				else
				{
					dp[i][k]=dp[i][t1]+2;
					t1=k-1;
				}
				//cout<<dp[i][k]<<" "<<dp[i][t1]<<" "<<t1<<endl;
			}
		} 
		//for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) cout<<dp[i][j]<<" ";
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=i;k<j;k++)
				{
					if(dp[i][k]+1==dp[i][j]&&x[j]-x[k]<=d) 
					{
						/*if(i==1&&j==5) 
						{
							cout<<i<<" "<<k<<" "<<dp[i][k]<<" "<<dp[i][j]<<" "<<dp1[i][k]<<"\n";
						}*/
						dp1[i][j]+=dp1[i][k];
					}
				}
				if(dp1[i][j]==2) 
				{
					//cout<<i<<" "<<j<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
