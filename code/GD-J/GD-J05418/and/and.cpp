#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,n[200006],o,dp[1000][9000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(ll i=1;i<=a;i++){
		cin>>n[i];
		if(i==1){
			o=n[i];
			dp[1][1]=o;
		}
		dp[i][1]=max(dp[i-1][1],n[i]);
}
	for(ll i=2;i<=a;i++){
		for(ll j=2;j<=b;j++){
			dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i-1][j-1]&n[i]));
			//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
		}
	}
	cout<<dp[a][b];
	return 0;
}
