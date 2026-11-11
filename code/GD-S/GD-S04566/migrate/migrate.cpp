#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+5;
ll c,t,n,m,a[N],d,dp[N][3],to[N];
void solve(){
	memset(dp,0,sizeof(dp));
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1,l=1;i<=n;i++){
		while(l<n&&a[l+1]-a[i]<=m)l++;
		to[i]=l;
	}
	long long ans=0;
	for(ll i=n;i;i--){
		if(i==to[i])continue;
		ans=ans+dp[to[i]][min(2ll,to[i]-i)];
		if(to[i]==to[i-1])dp[i][0]=0;
		else dp[i][0]=dp[to[i]][0]+to[i]-max(i,to[i-1]);
		if(to[i]==to[i-1])dp[i][1]=0;
		else dp[i][1]=dp[to[i]][min(2ll,to[i]-max(i,to[i-1]))];
		if(i>=3){
			ll to1=to[i],to2=to[i-1],to3=to[i-2];
			if(to2<=i)dp[i][2]=dp[to1][min(2ll,to1-i)];
			else if(to3<=i)dp[i][2]=dp[to1][min(2ll,to1-to2)]+to2-i;
			else if(to1==to3)dp[i][2]=0;
			else dp[i][2]=dp[to1][min(2ll,to1-to2)]+to2-to3;
		}
		else if(i==2){
			if(to[i-1]<=i)dp[i][2]=dp[to[i]][min(2ll,to[i]-i)];
			else dp[i][2]=dp[to[i]][min(2ll,to[i]-to[i-1])]+to[i-1]-i;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
