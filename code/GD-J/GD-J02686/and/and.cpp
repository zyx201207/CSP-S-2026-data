#include<bits/stdc++.h>
using namespace std;
int dp[200004][200004];
int sj[200004];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,s,ma=0,ans=0;
	cin>>a>>s;
	for(int i=0;i<a;i++){
		cin>>sj[i];
		dp[0][i]=sj[i];
	} 
	for(int i=1;i<a;i++){
		for(int j=1;j<=i;j++){
			ma=0;
			for(int g=0;g<i;g++) ma=max(ma,dp[j-1][g]&sj[i]);
			dp[j][i]=ma;
		} 
	}
	for(int i=0;i<a;i++) ans=max(ans,dp[s-1][i]);
	cout<<ans; 
	return 0;
} 
