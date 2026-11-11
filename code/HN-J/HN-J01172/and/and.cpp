#include<bits/stdc++.h>
using namespace std;
long long dp[200005],dpf[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+5];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=m;i++){
		dp[i]=dp[i-1]&a[i];
	}
	dpf[0]=2147483647;
	for(long long i=1;i<=n;i++){
		dpf[i]=max(dpf[i-1]&a[i],dpf[i]);
	}
	for(long long i=2;i<=n;i++){
		for(long long j=1;j<=m;j++){
			dp[j]=max(dpf[j-1]&a[i],dpf[j]);
		}
		for(long long j=1;j<=m;j++){
			dpf[j]=dp[j];
		}
	}
	cout<<dp[m];
	return 0;
}//2147483647
