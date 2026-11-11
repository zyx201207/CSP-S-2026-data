#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long LL;
LL n,m,a[N],c[N];
int dp[N][N];

int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		dp[1][i]=1;
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	c[1]=a[1];
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1) dp[i][j]=1;
			else dp[i][j]=0;
		}
	}
	
	for(int i=2;i<=n;i++){
		for(int j=c[i];j<=m;j++){
			dp[i][j]=max(dp[i-1][j-c[i]]+1,dp[i][j-1]);
		}
	}
	
	cout<<dp[n][m];
	return 0;
}
/*5 8
-3 -1 2 2 7*/
