#include<bits/stdc++.h>
using namespace std;
const int p=2*2*2*2*2*2;
const int o=p*p*p*p*p;
const int k=o*2-1;
long long n,m,a[222222],dp[222222];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;dp[0]=k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)dp[i]=dp[i-1]&a[i];
	for(int i=m+1;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}
