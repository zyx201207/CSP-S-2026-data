#include<bits/stdc++.h>
using namespace std;
int n,m;
int maxn;
int t[500005];
int dp[500005];//代表着选到dp[i]的最大数量 
int me[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t[i];
		dp[i]=1;
		me[i]=m;
	}
	for(int i=2;i<=n;i++){
		for(int d=1;d<i;d++){
			if(abs(t[i]-t[i-d])<=me[i-d]){
				dp[i]=max(dp[i-d]+1,dp[i]);
//				cout<<dp[i]<<endl;
				me[i]=me[i-d]-abs(t[i]-t[i-d]);
				maxn=max(maxn,dp[i]);
			}
		}
	}
	cout<<maxn;
	return 0;
}
