#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],dp[200005],ans,k=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(long long i=1;i<=31;i++){
		k*=2;
	}
	k--;
	cin >>n>>m;
	for(long long i=1;i<=n;i++){
		cin >>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long k=1;k<=i-1;k++){
			dp[1]=a[k];
			for(long long j=m;j>=1;j--){
				dp[j]=max(dp[j],dp[j-1]&a[i]);
				ans=max(ans,dp[j]);
			}
		}
		cout<<dp[m]<<" ";
	}
	cout<<dp[m];
	return 0;
} 
