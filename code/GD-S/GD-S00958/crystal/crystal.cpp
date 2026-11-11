#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll>v(n+1);
	for(ll i = 1; i <= n; i ++)cin>>v[i];
	sort(v.begin()+1,v.end());
	vector<ll>pre(n+1);
	ll num=0;
	for(ll i = 1; i <= n; i ++){
		pre[i]=v[i]+pre[i-1];
	}
	ll ans=0;
	for(ll i = 1; i <= n; i ++){
		ll l = 1, r = i, an;
		while(l<=r){
			ll mid = (l+r)/2;
			ll sum = pre[i]-pre[mid-1];
			if(v[i]*(i-mid+1)-sum<=m){
				an=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		ans = max(ans,i-an+1);
	}
	cout<<ans;
	return 0;
} 
