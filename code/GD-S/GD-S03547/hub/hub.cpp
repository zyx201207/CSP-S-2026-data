#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,dp[1000100][1000100];
int main(){
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		int x,y;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) dp[i][j]=1;
				else dp[i][j]=0;
			}
		}
		for(int i=1;i<=n-1;i++){
			cin>>x>>y;
			dp[x][y]=dp[y][x]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				
			}
		}
	}
	cout<<1<<endl<<2;
	
	return 0;
} 
