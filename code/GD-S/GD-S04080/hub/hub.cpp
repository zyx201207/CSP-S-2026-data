#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ll c,t;
	cin>>c>>t;
	
	for(ll i=0;i<t;i++){
		ll n,k;
		cin>>n>>k;
		
		vector<vector<ll>> num(n-1);
		for(ll ii=0;ii<n-1;ii++){
			ll ta,tb;
			cin>>ta>>tb;
			num[ta].push_back(tb);
			num[tb].push_back(ta);
		}
		
		cout<<k/2+c%2<<'\n';
	}
	
	return 0;
}
