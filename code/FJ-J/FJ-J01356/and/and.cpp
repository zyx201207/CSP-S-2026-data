#include<bits/stdc++.h>
using namespace std;
long long m,n,t=0,dp[200005],a[2000005];
long long f(long long n){
	long long ans=1;
	while(n){
		ans<<=1;
		n>>=1;
	}
	return ans>>1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	t=f(a[1]);
	for(long long i=1;i<=n;i++){
		if(a[i]>=t||i<=m)
			for(long long j=min(m,i);j>=1;j--){
				if(j==1) dp[j]=max(dp[j],a[i]);
				else dp[j]=max(dp[j],dp[j-1]&a[i]);
			}
		else break;
	}
	cout<<dp[m];
	return 0;
}