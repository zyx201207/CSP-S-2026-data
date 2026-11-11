#include<bits/stdc++.h>

using namespace std;
const long long M=10000000000005;
int n;
long long m;
int ans;
long long nl[M];
long long dp[M];
int main(){
	//GZ-S00318,安顺市第一高级中学，朱兴旺
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nl[i];
	}
	dp[1]=0;
    for(int i=1;i<=m;i++){
    	for(int j=1;j<=n;j++){
    		if(dp[j]<m) dp[j]=max(dp[j],dp[j+nl[i+1]]);
    	    if(dp[j]==m) break;
		}
	    ans++;
}
    cout<<ans<<'\n';
	fcolse(stdin);
	fclose(stdout);
	return 0;
}
