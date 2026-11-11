#include<bits/stdc++.h>
using namespace std;
int a[200005];
int dp[200005];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dp[i]=max(dp[i],(dp[i-1]&dp[j]));
			}
		}
		cout<<dp[n];
	}
	return 0;
}
