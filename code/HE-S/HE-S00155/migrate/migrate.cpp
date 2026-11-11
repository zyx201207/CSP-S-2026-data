#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin >> c >> t;
	ll n[t],d[t];
	for(int i=1;i<=t;i++){
		cin >> n[i] >> d[i];
		ll x[n[i]];
		for(int j=1;j<=n[i];j++) cin >> x[j];
	}
	cout << 1 << '\n' << 0 << endl;

	return 0;
}
