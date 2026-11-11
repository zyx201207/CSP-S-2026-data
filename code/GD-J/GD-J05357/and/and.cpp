#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long n,a[N],m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	    dp[i][1]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
//			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
			dp[i][j]=dp[i-1][j];
			if(i!=j)
			dp[i][j]=max(dp[i][j-1]&a[j],dp[i][j]);
//			dp[i][j]=max(dp[i][j],dp[i-1][j]);
//			cout<<dp[i][j]<<" ";
		}
//		cout<<endl;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<(31&15)<<endl;
	printf("%lld",dp[n][m]);
	return 0;
}/*
4 2 
3 15 12 12
5 3 
31 3 1 15 7
*/
