#include <iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[n]={};
	for(int i=0;i<n;i++) cin>>a[i];
	int dp[m][n]={};
	for(int i=0;i<n;i++) dp[0][i]=a[i];
	for(int i=1;i<m;i++){
		for(int j=0;j<n;j++){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j]&a[j]);
		}
	}
	cout<<dp[m-1][n-1];
	return 0;
}
