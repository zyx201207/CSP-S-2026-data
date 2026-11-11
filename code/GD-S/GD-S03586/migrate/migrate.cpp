#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;

vector<ll> P(2000006);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(ll i=1;i<=t;i++){
		P.clear();
		ll n,d;
		ll cnt=0;
		cin>>n>>d;
		for(ll j=1;j<=n;j++){
			ll a;
			cin>>a;
			P.push_back(a);
		}
		if(n<=2){
			cout<<0<<'\n';
		}else if(n==3){
			if(P[1]-P[0]<=d&&P[2]-P[1]<=d){
				if(P[2]-P[0]<=d){
					cout<<1<<'\n';
				}else{
					cout<<0<<'\n';
				}
			}else{
				cout<<0<<'\n';
			}
		}else if(n==4){
			ll ge=0;
			for(int i=0;i<=3;i++){
				if(P[i+1]-P[i]<=d){
					ge++;
				}
			} 
			if(ge==4){
				cout<<1<<'\n';
			}
		}else{
			cout<<2<<'\n';
		}
	}
}
