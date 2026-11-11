#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200001],dp[200001][2];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][1]=m;
	}
	sort(a+1,a+n+1);
	dp[1][0]=a[1];
	dp[1][1]=m-1;
	for(int i=2;i<=n;i++){
		if(dp[i-1][1]==n-i+1){
			for(int j=i;j<=n;j++)dp[j][0]=(dp[j-1][0]&a[j]);
			break;
		}
		if((dp[i-1][0]&a[i])<a[i]){
			dp[i-1][1]=m;
			dp[i][0]=a[i];
		}else if(dp[i-1][0]>(dp[i-1][0]&a[i])&&dp[i-1][1]>=1){
			dp[i][1]=dp[i-1][1];
			dp[i][0]=dp[i-1][0];
		}else{
			dp[i][1]=dp[i-1][1]-1;
			dp[i][0]=(dp[i-1][0]&a[i]);
		}
	}
	cout<<dp[n][0];
	return 0;
}//天灵灵，地灵灵，给个一等行不行！
