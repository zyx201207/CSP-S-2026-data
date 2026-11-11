#include<bits/stdc++.h>
#define ll long long
#define no ios::sync_with_stdio(0);
#define TLE cin.tie(0),cout.tie(0);
using namespace std;
const ll N=1e5+5;
ll n,k;
void solve(){
	cin>>n>>k;
	for(ll i=1,u,v;i<=n-1;i++)cin>>u>>v;
	ll m=n/2;
	ll x=max(0LL,m/2-k/2),y=min(m,m/2+k/2);
	cout<<max(x,m-y)<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	no TLE
	ll _=1;
	cin>>_>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
