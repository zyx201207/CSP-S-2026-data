#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int dp[N];
int n,m;
int a[N];
vector<int> wu;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<=n+10;i++) dp[i]=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=-1;
	for(int i=2;i<=n;i++)
	{
		for(int k=1;k<i;k++)
		{
			for(int j=0;j<=m;j++)
			{
				int v=a[i]-a[k];
				if(j>=v)
				{
					int zhi=dp[j]+1;
					dp[j-v]=max(dp[j-v],zhi);
				}
			}   
		}
		for(int j=0;j<=n+10;j++)
		{
			ans=max(ans,dp[j]);
		}
		for(int j=0;j<=n+10;j++) dp[j]=1; 
	}
	cout<<ans;
	return 0;
}
