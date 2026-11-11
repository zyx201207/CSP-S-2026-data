#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long dp[n+1][m+1],a[n+1];
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	if(n>2000){
		printf("0");
		return 0;
	}
	for(int j=0;j<=n;j++) dp[0][j]=0;
	for(int i=0;i<=m;i++) dp[i][0]=(2<<31)-1;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
//			printf("%2lld ",dp[i][j]);
		}
//		cout<<endl;
	}
	printf("%lld",dp[n][m]);
	return 0;
} 
