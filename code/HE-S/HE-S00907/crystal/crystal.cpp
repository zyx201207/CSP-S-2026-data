#include <bits/stdc++.h>

using namespace std;
int a[10001],dp[10000];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
 	dp[0]=1;
 	int cnt=m;
	for(int i=1;i<=n;i++){
		for(int j=a[i];j<=m;j++){
			dp[j]=max(dp[j],dp[j]+dp[j-a[i]]);
			
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		if(dp[i]==dp[m]){
			ans++;
		}

	}
	cout<<ans;
	return 0;
} 
