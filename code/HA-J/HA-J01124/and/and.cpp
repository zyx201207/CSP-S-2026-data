#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+10;
bool cmp(int x,int y){
	return x<y;
}
int dp[2005][2005];
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	dp[1][1] = a[1];
	for(int i = 2;i<=n;i++){
		dp[i][1] = a[i];
		for(int j = 2;j<=i;j++){
			dp[i][j] = max(dp[i-1][j],(dp[i][j-1] & dp[i-1][j-1]));
		}
	}
	cout<<dp[n][m];
	return 0;
}
