#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
const int N=2e3+42;
long long dp[N][N],a[N],n,m,maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	//dfs(1,2147483647,0);
	for(int i=0;i<=n;i++)dp[i][0]=2147483647;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j>i)break;
			if(j==1)dp[i][j]=max(dp[i-1][j],a[i]);
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
			if(j==m)maxn=max(maxn,dp[i][j]);
		}
	}
	cout<<maxn;
	return 0;
} 
