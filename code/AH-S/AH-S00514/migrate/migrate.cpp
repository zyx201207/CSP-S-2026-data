#include<bits/stdc++.h>
using namespace std;
const int N=5010;
long long dp[N][N],n,d,x[N],ans;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T,c;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		memset(dp,0,sizeof dp);
		ans=0;
		dp[1][0]=1;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=2;i<=n;i++)
			for(int j=1;j<i;j++)
			{
				if(x[i]-x[i-1]<=d) dp[i][j]++;
				for(int k=i-2;k>=2;k--)
					if(x[i]-x[k]<=d) dp[i][j]+=dp[k][j-1];
					else break;
			}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				if(dp[i][j]==2) 
				{
					ans++;
					break;
				}
		}
			
		cout<<ans<<"\n";
	}
	return 0;
}
