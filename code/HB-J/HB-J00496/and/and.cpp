#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int a[277777],dp[277777];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p=max(p,a[i]);
	}
	dp[1]=p;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp[2]=max(dp[2],a[i]&a[j]);
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=m;j>=3;j--){
			dp[j]=max(dp[j],(dp[j-1]&a[i]));
		}
	}
	cout<<dp[m];
	return 0;
}
