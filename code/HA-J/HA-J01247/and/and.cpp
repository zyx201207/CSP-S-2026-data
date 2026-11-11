#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=min(m,i);j>=1;j--){
			if(j==1){
				dp[j]=max(dp[j],a[i]);
			}else{
			if(i<=m){
				dp[j]=dp[j-1]&a[i];
			}else{
				dp[j]=max(dp[j],dp[j-1]&a[i]);
			}
			}
			
		}
	}
	cout<<dp[m];
	return 0;
}
