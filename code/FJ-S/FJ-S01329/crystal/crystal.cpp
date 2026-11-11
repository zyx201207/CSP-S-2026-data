#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5;
ll n,m,a[N],dp[N],sum[N],mmax;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+1;
		dp[i]=dp[i-1]+(a[i]-a[i-1])*sum[i-1];
		while(dp[i]>m){
			dp[i]-=(a[i]-a[i-sum[i]+1]),sum[i]--;
		} 
	}
	for(int i=1;i<=n;i++) mmax=max(mmax,sum[i]);
	cout<<mmax;
	return 0;
}