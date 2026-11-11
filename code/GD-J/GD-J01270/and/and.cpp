#include<bits/stdc++.h>
using namespace std;
#define int long long
int xh(int a,int b){
	int z=0;
	while(max(a,b)){
		if(a%2==1&&b%2==1){
			z+=1;
		}
		z*=2;
		a/=2;
		b/=2;
	}
	return z;
}
int dp[20010][20010],d[200100];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	dp[0][m-1]=d[0];
	for(int i=1;i<n;i++){
		for(int j=m-1;j>=0;j--){
			if(dp[i-1][m+1]==0)dp[i][j]=max(d[i],dp[i-1][m]);
			else dp[i][j]=max(xh(dp[i-1][m+1],d[i]),dp[i-1][m]);
		}
	}
	cout<<dp[n-1][0];
	
	return 0;
} 
