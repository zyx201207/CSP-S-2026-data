#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
using ll = long long;


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	io;
	ll c,t;
	cin>>c>>t;
	for(ll ts=0;ts<t;ts++){
		ll n,d;
		vector<ll> u; // up list
		u.clear();
		cin>>n>>d;
		u.resize(n);
		for(ll &i:u)cin>>i;
		ll ans = 0;
		for(ll i=0;i<n;i++){
            vector<ll> ways;
            ways.resize(n); // way number
			for(ll j=i+1;j<n;j++){
				if(u[j]-u[j-1]>d) { // j-1->j > d: can't add more;
					break;
				}else{
				    ways[j]++;
				}
				if (ways[j-1]>2) { // next will biger or beak
				    break;
				}
				for(int k = j-1;k>i;k--){ // try to jump dots from i -> . -> k -> j
				    if (u[j]-u[k]<d)ways[j]+=ways[k]; // can fly jump.
				    else break; // can't fly any
				}
				if (ways[j]==3) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


 
