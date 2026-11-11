#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[500001],dp[50001][5001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	dp[0][0]=2097151;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
		if(j-1<0)	dp[i][j]=dp[i-1][j];
		else	dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
	cout<<dp[n][m];
	return 0;
}

