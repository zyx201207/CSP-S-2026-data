#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll n,d;		
		vector<ll> a(n+1);
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>a[i];
		if(n<=3) cout<<0;
		else if(d<a[3]-a[1]){
			cout<<0<<endl;
			continue;
		}else{
			cout<<1<<endl;
			continue;
		}
	}
	return 0;
}

