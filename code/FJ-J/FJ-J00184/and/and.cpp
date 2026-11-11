#include <cstring>
#include <iostream>
using namespace std;
int dp[2009][2009],n,m,a[2009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][1]=max(dp[i-1][1],a[i]);
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=min(i,m);j++){
			for(int z=1;z<i;z++){
				dp[i][j]=max(dp[z][j],dp[z][j-1]&a[i]);
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}
