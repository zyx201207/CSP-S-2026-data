#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll n,d; cin>>n>>d;
		vector<ll> x;
		for(int i=1;i<=n;i++) cin>>x[i];
		int cnt=x[2]-x[1];
		if(n<4){
			cout<<0<<'\n';
			return 0; 
		}else if(n/d==2){
			cout<<1<<'\n';
			return 0;
		}
		else if(2*cnt==d){
			cout<<2<<'\n';
			return 0;
		}else cout<<0<<'\n';
		
	}
	return 0;
}
