#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,t;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll n,d;
		ll x[2000010];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			x[i]-=x[i-1];
		}
		if(d<=x[1]) cout<<0<<'\n';
		else if(d<=2*x[1]) cout<<0<<'\n';
		else if(d<3*x[1]) cout<<2*n-6<<'\n';
		else cout<<0<<'\n';
	}
	return 0;
}