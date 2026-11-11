#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5;
ll n,m;
ll a[N];
ll dp[N];
ll ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=1;
	}
	sort(a+1,a+1+n);
	for(ll i=n;i>=1;i--){
		ll now=a[i],sum=0;
		for(ll j=i-1;j>=1;j--){
			sum=sum+now-a[j];
			if(sum<=m) dp[i]++;
			else continue;
		}
	}
	for(ll i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
} 
