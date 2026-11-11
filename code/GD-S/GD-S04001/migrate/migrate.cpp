#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string ss;
const ll mmm=2e6+200;
const ll mod=1e9+7;
ll c,t;
ll dp[mmm];
ll dp2[mmm][10];
ll a[mmm];
ll n,d;
ll dfs(ll u){
	if(u>=n){
		return 0;
	}
	if(dp[u]!=-1) {
		return dp[u];
	}
	ll ans=1e15;
	for(ll i=1;i<=d;i++){
		if(u+i>n){
			break;
		}
		ans=min(ans,dfs(u+i)+1);
	}
	dp[u]=ans;
	return dp[u];
} 
ll dfs2(ll u,ll sum){
	if(u>=n&&sum==0){
		return 1;
	}
	if(sum<=0&&u<n){
		return 0;
	}
	if(dp2[u][sum]!=-1){
		return dp2[u][sum];
	}
	ll ans=0;
	for(ll i=1;i<=d;i++){
		if(u+i>n){
			break;
		}
		ans+=dfs2(u+i,sum-1);
	}
	dp2[u][sum]=ans;
	return ans;
} 
ll x[mmm];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(ll l=1;l<=t;l++){
		cin>>n>>d;
		memset(dp,-1,sizeof(dp));
		memset(dp2,-1,sizeof(dp2));
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		ll sum=dfs(1);
		x[l]=dfs2(1,sum)/2;
	}
	for(ll i=1;i<=t;i++){
		cout<<x[i]<<endl;
	}
	return 0;
}
