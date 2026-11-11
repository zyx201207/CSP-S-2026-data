#include<bits/stdc++.h>
using namespace std;
int a[1000005],dp[1000005],cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int mx=-1;
		for(int i=1;i<=n;i++){
			if(a[i]>mx) mx=a[i];
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
		    dp[i]|=a[i];
		}
		cout<<dp[n];
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(cnt==m) {
		cout<<dp[i-1];
		break;
	}
		dp[i]=max(dp[i-1],dp[i-1]|a[i]);
		if(dp[i]==dp[i-1]|a[i]&&dp[i-1]!=dp[i-1]|a[i]) cnt++;
	}
	return 0;
}
