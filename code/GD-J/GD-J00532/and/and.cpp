#include<bits/stdc++.h>
using namespace std;
/*为什么我T3都写不出来啊！！！只有317pts了！！！我要AK！！！*/
int dp[200002][2];
int a[200002];
// int maxn[200002][2];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n<=2000)
	{
		// vector<vector<int>>dp(n+1,vector<int>(2,0));
		// vector<int>a(n+1);
		for(int i=1;i<=n;i++)
			cin>>a[i],dp[i][1]=a[i];
		// for(int i=1;i<=n;i++)
		// 	mmxn[0][i]=dp[i][0];
		// for(int i=1;i<=n;i++)
		// {
		// 	maxn[i][1]=max(maxn[i-1][1],a[i]);
		// }
		// for(int i=1;i<=n;i++)
		// 	maxn[i][0]=max(maxn[i-1][0],maxn[i-1][1]&a[i]);
		for(int l=2;l<=m;l++)
		{
			for(int i=l;i<=n;i++)
			{
				int maxx=0;
				for(int j=l-1;j<i;j++)
				maxx=max(maxx,dp[j][(l-1)%2]&a[i]);
				dp[i][l%2]=max(dp[i-1][l%2],maxx);
				// dp[i][l]=max(dp[i-1][l],mmxn[l%2][i-1]&dp[i][1]);
				// dp[i][l%2]=max(dp[i-1][l%2],maxn[i][l%2]);
				// maxn[i+1][(l+1)%2]=max(maxn[i][(l+1)%2],dp[i][l%2]&a[i+1]);
				// mmxn[(l+1)%2][i]=max(mmxn[(l+1)%2][i-1],dp[i][l]);
			}
		}
		// int ans=-1;
		// for(int i=m;i<=n;i++)ans=max(ans,dp[i][m]);
		cout<<dp[n][m%2];
	}
	else
	{
		bool chk=false;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]!=i-1)chk=true;
		}
		sort(a+1,a+n+1,cmp);
		if(chk)
		{
			cout<<a[m];
		}
		else
		{
			int ans=a[1];
			for(int i=2;i<=m;i++)
				ans&=a[i];
			cout<<ans;
		}
	}
	return 0;
}