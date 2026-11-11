#include<bits/stdc++.h>
using namespace std;
int n,m,dp[2050][2050];
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>dp[1][i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=i+1;k<=n;k++){
				dp[j+1][k]=max(dp[j][i]&dp[1][k],dp[j+1][k]);
			}
		}
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		mx=max(dp[m][i],mx);
	}
	cout<<mx;
} 
