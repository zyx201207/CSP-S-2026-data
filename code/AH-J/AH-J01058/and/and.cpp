#include<bits/stdc++.h>
using namespace std;
const int N=2*1e3+1;
long long n,m,a[N],dp[N][N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	dp[1][1]=a[1];
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(j!=m)
			dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]&a[i]),a[i]);
			else
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	cout<<dp[n][m];
	return 0;
}
