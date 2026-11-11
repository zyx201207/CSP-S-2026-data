//蒋木铮 GZ-J00132 贵阳第一中学 
#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n,dp[N][N],m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],dp[i][1]=max(dp[i-1][1]&a[i],a[i]);
	for(int i=1;i<=n;i++){
		for(int j=2;j<=min(i,m);j++){
			dp[i][j]=max(dp[i-1][j-1]&a[i],dp[i-1][j]);
		}
	}
	cout<<dp[n][m];
	return 0;
}
