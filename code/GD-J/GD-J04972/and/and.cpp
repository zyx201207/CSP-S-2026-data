#include<bits/stdc++.h>
using namespace std;
const int f=2e5+5;
long long dp[1000][10];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[f];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	dp[2][2]=a[1]&a[2];
	for(int i=1;i<=n;i++) dp[i][1]=a[i];
	for(int i=2;i<=m;i++){
		for(int j=i+1;j<=n;j++){
			dp[j][i]=max(dp[j-1][i],dp[j][i-1]&a[i]);
		}
	}
	cout<<dp[n][m];
	return 0;
}

