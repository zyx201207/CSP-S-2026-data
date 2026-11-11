#include<bits/stdc++.h>
#define ll long long
using namespace std;ll n,m,a[200005],ans;
unordered_set<ll>lkd;
ll dfs(){
	ll mx;
	for(ll i=1;i<=n;i++){
		if(lkd.count(a[i]))continue;
		lkd.insert(a[i]);
		mx=max(mx,a[i]&dfs());
		lkd.remove(a[i]);
	}
	return mx;
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++){
		lkd.insert(a[i]);
		ans=max(ans,dfs());
		lkd.remove(a[i]);
	}cout<<ans;
	return 0;
}
