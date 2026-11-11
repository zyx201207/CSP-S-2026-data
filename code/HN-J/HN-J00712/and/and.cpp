#include<iostream>
using namespace std;
int n,m;
const int N=20000;
int a[N];
int dp[N][N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];	
	dp[i][0]=a[i]; 
	}
	int sum=0;
	for(int i=1;i<=n;i++){//共有n 
		for(int j=1;j<=n;j++){//目前第几个 
		for(int k=1;k<=m;k++){
			dp[i][j]=max(dp[i][j-1],dp[i][j]&a[k]); 
				}
	}
}
	cout<<dp[n][m];
	/*
	4 2
	3 15 12 12
	 
	 5 3
	 31 3 1 15 7
	*/
	return 0;
}
