#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll random(ll x){
	ll n=rand()%x;
	return n;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(static_cast<unsigned>(time(0)));
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=q;i++){
		cout<<random(101)<<endl;
	}
	return 0;
} 
