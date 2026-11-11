#include<bits/stdc++.h>
using namespace std;
int dp[200086],v[200086];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
	dp[0]=2147483647;
	for(int i=1;i<=n;i++){
		for(int j=min(i,m);j>=1;j--){
			dp[j]=max(dp[j],(dp[j-1]&v[i]));
		}
	}
	cout<<dp[m];
	return 0;
}
