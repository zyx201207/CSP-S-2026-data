#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m;
int a[maxn],dp[maxn];
int ans;
void dfs(int x,int pick,int sum)
{
	if(pick==m)
	{
		ans=max(ans,sum);
		return;
	}
	if(x>n)
		return;
	dfs(x+1,pick,sum);
	if(pick==0)
		sum=a[x];
	else
		sum&=a[x];
	dfs(x+1,pick+1,sum);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n>=20&&n<=2000)
	{
		dfs(1,0,0);
		cout<<ans<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=min(i,m);j>=2;j--)
				dp[j]=max(dp[j],dp[j-1]&a[i]);
			dp[1]=max(dp[1],a[i]);
		}
		cout<<dp[m]<<endl;
	}
	return 0;
}
