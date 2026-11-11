#include <bits/stdc++.h> 
using namespace std; 
int dp[200001][2000001]={};
int k[200001][2000001]={};
int n,m;
int sum=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and .out","w",stdout);
	cin>>n>>m;
	int x=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		dp[0][i]=x;
		dp[i][0]=x;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
			continue;
			}
			else if(dp[i][j]<=(dp[i-1][j]&&dp[i][0])){
				dp[i][j]=(dp[i-1][j]&&dp[i][0]);
				k[i][j]++;
			}
			if(k[i][j]==m){
				sum=dp[i][j];
			}
		}
	}
	cout<<sum;
	return 0;
}
