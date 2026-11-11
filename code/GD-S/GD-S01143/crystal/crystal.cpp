#include<bits/stdc++.h>
using namespace std;
long long n,m,arr[500010],dp[500010],dp1[500010],maxn=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		dp[i]=1;
	}
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if((arr[i]-arr[j])*dp[j]+dp1[j]<=m){
				if(dp[j]+1>dp[i]){
					dp1[i]=(arr[i]-arr[j])*dp[j]+dp1[j];
					dp[i]=dp[j]+1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		maxn=max(maxn,dp[i]);
	}
	cout<<maxn;
	return 0;
}

