#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e3*2+10;
int n,m;
int arr[MAXN],dp[MAXN][MAXN];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	
	for(int i=0;i<=m;i++) dp[0][i]=0;
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j]=dp[i-1][j];
			dp[i][j]=max(dp[i][j],dp[i-1][j+1]&arr[i]);
		}
	} 
	
	cout<<dp[n][m];
	
	return 0;
}
