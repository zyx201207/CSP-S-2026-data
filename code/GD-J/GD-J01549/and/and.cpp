#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],dp[N];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	dp[2]=a[1]&a[2];
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			dp[j]=max(dp[j],dp[j+1]&a[i]);
			cout<<dp[j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[m]<<endl;
	return 0;
}
