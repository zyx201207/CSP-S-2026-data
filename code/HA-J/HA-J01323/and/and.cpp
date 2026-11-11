#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int op1=n+5;
	int op2=m+5;
	long long dp[op1][op2];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[i][m-1]=a[i];
		for(int j=1;j<=m;j++){
			dp[i][j]=max(dp[i][j],(dp[i-1][j-1]&a[i]));
		}
	}
	cout<<dp[n][m];
	return 0;
}
