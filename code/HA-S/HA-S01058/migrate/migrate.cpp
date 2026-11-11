#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll c,t;
ll n,d,x[2000010],dx;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (ll ind=1;ind<=t;ind++){
		cin>>n>>d;
		for (ll i=1;i<=n;i++){
			cin>>x[i];
		}
		if (n==1){
			cout<<0<<endl;
			continue;
		}
		if (d>=x[n]-x[1]){
			cout<<0<<endl;continue;
		}
		dx=x[2]-x[1];
		if (d<=dx){
			cout<<0<<endl;
			continue;
		}
		cout<<2*n*(d-2)-(3*(d-1)*d)/2<<endl;
	}
	
	return 0;
}
