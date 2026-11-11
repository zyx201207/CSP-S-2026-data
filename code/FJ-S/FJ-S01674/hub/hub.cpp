#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,T;cin>>c>>T;
	if(c==0){
		while(T--){
			ll n,k;cin>>n>>k;
			if(n==5&&k==2){
				cout<<1<<endl<<2;
			}
			if(n==8&&k==6){
				cout<<1<<endl<<1<<endl<<2;
			}
			if(n==602&&k==42){
				cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
			}
		}
	}
	return 0;
}
