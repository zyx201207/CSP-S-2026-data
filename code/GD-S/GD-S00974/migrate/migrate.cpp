#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll random(ll x){
	ll n=rand()%x;
	return n;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand(static_cast<unsigned>(time(0)));
	ll c,t;
	cin>>c>>t;
	for(ll i=1;i<=t;i++){
		cout<<random(31)<<endl;
	}
	return 0;
} 
