#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,a[500005],s[500005],d[500005];
long long dp[500005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a[0]=0;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
		dp[i]=1;
		s[i]=s[i-1]+a[i];
		d[i]=a[i]-a[i-1];
	}
	for(long long i=1; i<=n; i++) {
		for(long long j=i-1; j>=1; j--) {
			m-=d[j+1]+s[j+1]-s[1];
			if(m<0) dp[i]=max(dp[i],i-j);
			else if(m==0) dp[i]=max(dp[i],i-j+1);
		}
		cnt=max(cnt,dp[i]);
	}
	cout<<cnt;
	return 0;
}
