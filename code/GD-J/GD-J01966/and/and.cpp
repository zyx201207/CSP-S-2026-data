#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long dp[2][200010];
int n,m;
long long maxn;
void dfs(int now,int cnt,long long sum)
{
	if(now>n)
	{
		if(cnt==m)maxn=max(maxn,sum);
		return;
	}
	if(cnt==m)
	{
		maxn=max(maxn,sum);
		return;
	}
	
	dfs(now+1,cnt+1,sum&a[now]);
	dfs(now+1,cnt,sum);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=20)
	{
		dfs(1,0,1ll*((1ll*1)<<31)-1ll);
		cout<<maxn;
	}
	else 
	{
		dp[0][0]=dp[1][0]=1ll*((1ll*1)<<31)-1ll;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dp[i%2][j]=max(dp[(i-1)%2][j],dp[(i-1)%2][j-1]&a[i]);
			}	
		} 
		cout<<max(dp[0][m],dp[1][m]);
	}
//	cout<<endl<<(1ll*((1ll*1)<<31)-1ll)<<endl<<1ll*2147483647*2;
	return 0;	
} 
