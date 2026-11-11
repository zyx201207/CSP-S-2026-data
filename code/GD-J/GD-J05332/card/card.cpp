#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],dp[3005],s[3005],ans[3005];
bool vis[5005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=1000)
	{
		for(int i=1;i<=n;i++)
		{
			dp[a[i]]=i;
			for(int j=i+1;j<=n;j++)
			{
				if(dp[a[j]]==0)dp[a[j]]=j;
				else 
				{
					for(int k=j-1;k>dp[a[j]];k--)
						dp[a[k]]=0;
					dp[a[j]]=j;
				}
			}
			for(int j=1;j<=n;j++)
				if(dp[a[j]])ans[a[j]]++,dp[a[j]]=0;
		}
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		if(i==a[n])cout<<n<<" ";
		else cout<<"0 ";
	}
	return 0;
}
