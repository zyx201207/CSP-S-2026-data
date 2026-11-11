#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005];
int w[200005];
int n,m;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
//int f=3&15;
//cout<<f<<endl;
cin>>n>>m;
int maxx=0;
for(int i=1;i<=n;i++){
	cin>>w[i];
	//maxx=max(w[i],maxx);
//	dp[i][0]=w[i];
}
/*
5 3
31 3 1 15 7
*/
//cout<<f<<endl;
/*
4 2
3 15 12 12
*/
//sort(w+1,w+n+1);
for(int i=0;i<=n;i++){
	if(i!=0){
		dp[i][0]=w[i];
	}else{
		dp[i][0]=w[1];
	}
	
}
for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
			if(j-1>=0){
			int f=dp[i-1][j-1]&w[i];
			dp[i][j]=max(dp[i-1][j],f);
		}
	}
}
//cout<<dp[1][2]<<endl;
cout<<dp[n][m]<<endl;
	return 0;
}
