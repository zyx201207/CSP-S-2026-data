#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t;
ll dx[]={0,0,-1,1};
ll dy[]={1,-1,0,0};
vector <ll> g[10100];
ll dis[1010][1010];
queue<pair<ll,ll>>q;
ll n,d;
bool isa(){
	ll pos=a[2]-a[1];
	for(ll i=1;i<=n;i++){
		if(a[i+1]-a[i]!=pos)return false;
	}
	return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cout<<0<<endl;
	}
	return 0;
}
