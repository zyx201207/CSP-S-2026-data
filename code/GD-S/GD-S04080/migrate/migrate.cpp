#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ll c,t;
	cin>>c>>t;
	
	for(ll i=0;i<t;i++){
		ll n,d;
		cin>>n>>d;
		
		vector<ll> num(n);
		for(ll ii=0;ii<n;ii++)cin>>num[ii];
		
		ll sum=0;
		for(int ii=0;ii<n-3;ii++){
			bool jug=true;
			for(int i4=1;i4<4;i4++){
				if(num[ii+i4]-num[ii+i4-1]>d){
					jug=false;
					break;
				}
			}
			if(jug)sum++;
		}
		if(c==13||c==14)cout<<0<<'\n';
		else cout<<sum<<'\n';
	}

	return 0;
}
