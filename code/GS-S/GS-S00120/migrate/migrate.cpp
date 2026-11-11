#include <bits/stdc++.h>
using namespace std;
#define ll long long
int c,t;
ll n,d;
ll x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		ll dc=x[2]-x[1];
		ll k=ceil(d*1.0/dc*2.0);
//		cout<<k<<" "<<dc<<'\n';
//		cout<<k1<<endl;
		if(k<=2){
			cout<<0<<'\n';
			continue;
		}else{
			if(k>n){
				cout<<0<<'\n';
				continue;
			}
			else{
				cout<<n-k+1<<'\n';
			}
		}
	}
	return 0;
}
