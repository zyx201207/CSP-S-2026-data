#include<bits/stdc++.h>
using namespace std;
int a[200005];
int dp[200005];
int ans=-1;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mxa=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mxa=max(a[i],mxa);
	}
	if(n==1){
		cout<<a[1];
		return 0;
	}
	if(n==2){
		if(m==1){
			cout<<mxa;
			return 0;
		}
		int a1=a[1];
		int a2=a[2];
		cout<<(a1&a2);
		return 0;
	}
	if(m==n){
		int sum=a[1];
		for(int i=1;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}
	dp[1]=mxa;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[j]=dp[j-1];
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}
