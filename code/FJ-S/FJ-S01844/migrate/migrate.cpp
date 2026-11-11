#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using pii=pair<int,int>;
const int N = 2e6+10;
int c,t,n,d;
int x[N];
int dp[5000][5000];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(x[2]-x[1]!=1)
		{
			cout<<0;
			continue;
		} 
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(abs(i%2)==1)
				{
					if(abs(j)%2==1) dp[i][j]=1;
					else dp[i][j]=dp[i][j-2]+1;
				}
				else
				{
					if(abs(j)%2==0) dp[i][j]=1;
					else dp[i][j]=dp[i][j-2]+1;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(dp[i][j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 

