#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int a[N],dp[N][N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int Max=0;
	for(int i=1;i<=n;i++){
		Max=max(Max,a[i]);
		dp[i][1]=Max;
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=i;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	cout<<dp[n][m];
	return 0;
}
