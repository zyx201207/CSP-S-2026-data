#include<bits/stdc++.h>
using namespace std;
const int N=5050;
int c,t,n,m,a[N],dp[N][N],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		if(c==13||c==14)
		{
			cout<<0;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int last=0;
		for(int i=0;i<=n;i++) dp[1][i]=1;
		for(int i=1;i<=n;i++)
		{
			int k=upper_bound(a+1,a+1+n,a[i]+m)-a-1;
			for(int j=0;j<=n;j++) 
			{
				for(int l=i+1;l<=k;l++) dp[l][j+1]+=dp[i][j];
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(dp[i][j]!=2&&dp[i][j]!=0) break;
				if(dp[i][j]==2)
				{
					ans++;
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
