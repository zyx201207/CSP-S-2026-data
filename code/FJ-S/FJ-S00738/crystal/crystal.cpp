#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
ll dp[500005];
ll bnn(ll q,ll zz){
	ll e=m,ans=0;
	while(e>=(zz-a[q-1])&&q-1>0)ans++,e-=zz-a[--q];
	return ans;
}
int main(){
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(ll i=1;i<=n;i++){
	scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	dp[1]=1;
	for(ll i=2;i<=n;i++){
		ll ans=1;
		ll q=i;
		while(a[q]==a[q+1]&&q+1<=n){
			ans++;
			q++;
		}
		dp[i]=max(dp[i-1],ans+bnn(i,a[i]));
		dp[q]=dp[i];
		i=q;
	}
	cout<<dp[n];
	return 0;
}
