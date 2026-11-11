#include<bits/stdc++.h>
using namespace std;
const int N=2*100000+100;
int e[N];
int vis[N];
int n,m;
int mx;
void dfs(int x,int s)
{
	if(x>n||s>m)
	{
		if(s==m+1)
		{
			int ans=vis[1];
			for(int i=2;i<=m;i++)
			{
				ans=(ans&vis[i]);
			}
			mx=max(mx,ans);
		}
		return;
	}
	vis[s]=e[x];
	dfs(x+1,s+1);
	vis[s]=0;
	dfs(x+1,s);
}

void s1()
{
	dfs(0,1);
	cout<<mx;	
}
int dp[10000][10000];
void s2()
{
	int mn=0;
	dp[1][1]=e[1];
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=max(e[i],dp[i-1][1]);
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			if(i>j)
			dp[i][j]=max(dp[i-1][j],(dp[i-1][j-1]&e[i]));
			else if(i==j) dp[i][j]=dp[i-1][j-1]&e[i];
		}
	}

	cout<<dp[n][m];
}
void s3()
{
	
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>e[i];
	}

	
	if(n<=20)
	{
		s1();
	}
	else s2();

	return 0;
 } 
