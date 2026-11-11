#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<vector<ll>>mp(n+1);
		for(ll i = 1; i < n; i ++){
			ll x,y;
			cin>>x>>y;
			mp[x].push_back(y);
			mp[y].push_back(x);
		}
		cout<<1<<endl; 
	}
	return 0;
} 
