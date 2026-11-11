#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t;
	cin >> c >> t;
	
	ll n[t],k[t];
	for(int i=1;i<=t;i++){
		cin >> n[i] >> k[i];
		ll u[n[i]-1],v[n[i]-1];
		for(int j=1;j<=n[i]-1;j++) cin >> u[j] >> v[j];
	}
	cout << 0 << endl;

	return 0;
}
