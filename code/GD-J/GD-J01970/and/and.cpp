#include<bits/stdc++.h>
using namespace std;
int dp[200010],n,m,jl[200010],da=0;
void dfs(int w,int h)
{
	if(h==m)
	{
		int ans=pow(2,30)-1;
		for(int i=0;i<h;i++)ans=(ans&jl[i]);
		da=max(da,ans);
		return ;
	}
	else
	{
		/*
		5 3
31 3 1 15 7
		*/
		for(int i=w+1;i<=n-m+h+1;i++)
		{
			jl[h]=dp[i];
			dfs(i,h+1);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>dp[i];
    if(m==n)
    {
    	int ns=pow(2,30)-1;
		for(int i=1;i<=n;i++)ns=(ns&dp[i]);
		cout<<ns;
		return 0;
	}
	else
	{
		sort(dp+1,dp+n+1);
    	for(int i=1;i<=n;i++)
    	{
    		jl[0]=dp[i];
			dfs(i,1);
		}
		cout<<da;
	}
	return 0;
}
