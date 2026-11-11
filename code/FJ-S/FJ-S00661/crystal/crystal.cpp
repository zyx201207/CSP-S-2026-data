#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],maxx=0,su[500005],dp[500005];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		su[i]=su[i-1]+a[i];
		ll t=su[i]+m;
		if(a[i]==a[i-1]){
			dp[i]=dp[i-1]+1;
			maxx=max(maxx,dp[i]);
			continue;
		} 
		for(int x=i;x>=1;x--){
			if(a[i-x]+m<a[i]) continue; 
			dp[i]=t-su[i-x];
			if(dp[i]/x<=a[i]){
				dp[i]/=a[i];
				maxx=max(maxx,dp[i]);
				break; 
			}
		}
	}
	cout<<maxx;
	return 0;
} 
