#include<bits/stdc++.h>
#define ll long long 
ll a[10000005];
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t,sum=0;
	cin>>c>>t;
	ll w=0;
	while(t--){
		ll n,d;
		ll m=n;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			sum++;
		}
		if(sum%2==0){
			cout<<1;
			return w;
		}else{
						cout<<0;
			return w;
		}
	}
	
	return 0;
} 
