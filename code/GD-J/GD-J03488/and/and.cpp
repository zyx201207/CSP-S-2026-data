#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],dp[200005][200005];
int main(){
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	memset(dp,0,sizeof(dp));
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		dp[i][1]=a[i]; 
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			if(j>i)break;
			dp[i][j]=max({dp[i][j],dp[i-1][j-1]&a[i],dp[i-1][j]});
		}
	}
//	long long maxn=-1;
//	for(long long i=1;i<=n;i++)maxn=max(dp[i][m],maxn);
//	cout<<maxn;
	cout<<dp[n][m];

	return 0;
} 
/*
4 2
3 15 12 12
5 3
31 3 1 15 7
*/
