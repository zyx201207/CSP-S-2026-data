#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
ll dp[500005];
void solve(ll num){
	dp[num]=dp[num-1]+(num-1)*(a[num]-a[num-1]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll ans=0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[1]=0;
	for(ll i=2;i<=n;i++){
		solve(i);	
		if(dp[i]>m){
			cout<<i-1<<'\n';
			return 0;
		}
		if(i==n){
			cout<<i<<'\n';
			return 0;
		}
		
		//cout<<dp[i]<<'\n';
	}
	//cout<<ans<<'\n';
	return 0;
}
