#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<bool> kl;
int main(){
	//freopen("migrate.in","r",stdin);
	ll c,t;
	cin>>c>>t;
	for(int i = 1;i <= t;i++){
		ll n,d;
		cin>>n>>d;
		ll dy[n+5];
		for(ll i = 1;i <= n;i++){cin>>dy[i];}
		//kl.resize(dy[n]+5);
		//for(ll i = 1;i <= n;i++){kl[dy[i]] = 1;}
		if(dy[2] - dy[1] == dy[3]-dy[2]){
			ll m = dy[2] - dy[1];
			if(d <= m){
				cout<<0;
			}else{
				ll op = (d-d%m)/m;
				cout<<n/op-1;
			}
		}else{
			ll mid = (dy[1]+dy[n])>>1;
			cout<<"erorr2";
		}
	}
	//freopen("migrate.ans","w",stdout);
	return 0;
}
