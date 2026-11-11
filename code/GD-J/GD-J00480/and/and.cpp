#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[2010];
long long dp[2010][2010];//dp[前i个][选几个]=最大值 
long long maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	maxx=-1e12;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		dp[i][1]=maxx;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=2;j--){
			dp[i][j]=max(dp[i-1][j],(dp[i-1][j-1]&a[i]));
		}
	}
	maxx=-1e12;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,dp[i][m]);
	}
	cout<<maxx;
	return 0;
}
