#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Dp{
	ll sum,len,maxn;
}dp[500010];
	ll n,m;
	ll a[500010];
	ll ans=1;
ll f(ll x,ll y){
	return x>y;
}
ll abss(ll x){
	if(x<0)return -x;
	return x;
}
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	
	if(m==0){cout<<"1";return 0;}
	ll pf=1;
	for(ll i=3;i<=n;i++)if((a[i]-a[i-1])!=(a[i-1]-a[i-2])){pf=0;break;}
	if(pf==1){
		ll k=abss(a[2]-a[1]);
		cout<<(long long)((sqrt(8.0*m/k+1)-1)/2)+1;
		return 0;
	}
	
	sort(a+1,a+n+1,f);
	for(ll j=1;j<=n;j++){
		dp[j].len=1;
		dp[j].sum=0;
		dp[j].maxn=a[j];
		ll ans1=1;
		for(ll i=j+1;i<=n;i++){
			if(dp[i-1].sum+(dp[i-1].maxn-a[i])<=m){
				dp[i].sum=dp[i-1].sum+(dp[i-1].maxn-a[i]);
				dp[i].maxn=dp[i-1].maxn;
				dp[i].len=dp[i-1].len+1;
				ans1=max(ans1,dp[i].len);
			}
			else break;
		}
		ans=max(ans,ans1);
	}
	cout<<ans<<"\n";
	return 0;
}
//T1
//csp-s 2026 RP++!
