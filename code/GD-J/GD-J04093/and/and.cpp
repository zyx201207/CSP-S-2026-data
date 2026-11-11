#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=1;cin>>n>>m;
	vector<int>a(n+1);
	vector<vector<int> >dp(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)dp[i][1]=a[i];
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			dp[i][j]=max({dp[i-1][j-1]&a[i],dp[i-1][j]});
		}
	}
	cout<<dp[n][m];
	return 0;
} 
