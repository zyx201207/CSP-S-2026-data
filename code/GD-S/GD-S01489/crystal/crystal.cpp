#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000000],dp[10000000],ans=-10000000,r,d[10000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	r=m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++) d[i]=a[i]-a[i-1];
	dp[1]=1;
	for(long long i=2;i<=n;i++){
		if(m-d[i]*dp[i-1]>=0&&d[i]>=0){
			dp[i]=dp[i-1]+1;
			m-=d[i]*dp[i-1];
		}else {
			dp[i]=1;
			m=r;
		}
	}
	for(long long i=1;i<=n;i++){
		if(ans<dp[i]) ans=dp[i];
	}
	cout<<ans<<endl;
	return 0;
} 
