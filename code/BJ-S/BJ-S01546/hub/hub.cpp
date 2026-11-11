#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		for(ll i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
		}
		if(k%2==1){
			cout<<(n+1)/2-(k-1)/2-1;
		}
		else{
			cout<<(n+1)/2-k/2;
		}
		cout<<'\n';
	}
	return 0;
}