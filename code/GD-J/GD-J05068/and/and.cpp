#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200007];
map<int,long long> dp[200007];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][1]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(m,i);j++){
			dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i-1][j-1]&a[i]));
		}
	}
	cout<<dp[n][m];
	return 0; 
}
