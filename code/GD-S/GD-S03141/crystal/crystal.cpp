#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],n,m,ans=LLONG_MIN;
ll dfs(ll depth){
	if(depth==m){
		map<ll,ll> mp;
		ll eq=LLONG_MIN;
		for(int i=1;i<=n;i++) mp[a[i]]++;
		for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();it++) eq=max(eq,it->second);
		return eq;
	}
	ll ans=LLONG_MIN;
	for(int i=1;i<=n;i++){
		a[i]++;
		ans=max(ans,dfs(depth+1));
		a[i]--;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf(" %lld",a+i);
	printf("%lld",dfs(0));
	return 0;
}
