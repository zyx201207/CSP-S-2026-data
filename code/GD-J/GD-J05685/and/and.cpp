#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int maxn=2e5+5;
int dp[maxn][maxn];
int s[maxn];
int t[maxn];
int n,m;
int ans=0;
int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
	}
	for(int i=0;i<=m;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++){
		dp[i][1]=max(s[i],dp[i-1][1]&s[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(i>=j){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&s[i]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}

