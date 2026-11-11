#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m;
long long a[N];
long long dp[N][N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j]=1;
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
			if(i!=1 && j>=(i-1)*(a[i]-a[i-1])) dp[i][j]=max(dp[i][j],dp[i-1][j-(i-1)*(a[i]-a[i-1])]+1);
		}
	}
	//cout<<1;
	cout<<dp[n][m];
	
	
	
	return 0;
}


/*
5 5
1 2 4 8 9


5 8
-3 -1 2 2 7
*/
