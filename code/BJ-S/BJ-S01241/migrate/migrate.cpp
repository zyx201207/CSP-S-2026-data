#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long fun,t;
}dp[5005][5005];
long long c,t,n,d,x[200005],ans;
vector<long long> G[200005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	cin.tie(0);
	cin>>c>>t;
	for(long long oo = 1;oo <= t;oo++)
	{
		ans = 0;
		cin>>n>>d;
		for(long long i = 1;i <= n;i++)
		{
			for(long long j = 1;j <= n;j++)
			{
				dp[i][j] = {0,1100000000000000000};
			}
			cin>>x[i];
			G[i].clear();
			long long j = i-1;
			while(j >= 1 && x[i]-x[j] <= d)
			{
				G[i].push_back(j);
				j--;
			}
			dp[i][i] = {1,0};
		}
		for(long long i = 1;i <= n;i++)
		{
			for(long long j = i+1;j <= n;j++)
			{
				for(long long k = 0;k < (long long)G[j].size();k++)
				{
					long long v = G[j][k];
					if(v >= i)
					{
						if(dp[i][v].t+1 < dp[i][j].t)
						{
							dp[i][j] = {dp[i][v].fun,dp[i][v].t+1};
						}
						else if(dp[i][v].t+1 == dp[i][j].t)
						{
							dp[i][j].fun+=dp[i][v].fun;
						}
					}
				}
				//cout<<i<<" "<<j<<" "<<dp[i][j].fun<<","<<dp[i][j].t<<" ";
				if(dp[i][j].fun == 2)
				{
					ans++;
				}
			}
			//cout<<endl;
		}
		cout<<ans<<endl;
	}
}
