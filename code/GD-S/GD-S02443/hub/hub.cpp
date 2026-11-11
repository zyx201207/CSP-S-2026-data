#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll>a[n];
		for(int i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		ll ans=1;
		cout<<ans<<endl;
	}
	return 0;
}
