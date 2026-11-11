#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp(2005,vector<int>(2005,0));
vector<int>a(2005,0);
const int full=1048575;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[i][0]=full;
	}
	dp[1][1]=a[1];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(j>m)break;
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	printf("%d",dp[n][m]);
}
