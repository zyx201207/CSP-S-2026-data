#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,k,u[1000005],v[1000005],mbfl=1;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(ll i=1;i<=t;++i){
		cin>>n>>k;
		for(ll j=1;j<=n-1;++j){
			cin>>u[j]>>v[j];
		}
		bool f=1;
		for(ll j=2;j<=n-1;++j){
			if(u[j]!=v[j-1]){
				cout<<mbfl++<<endl;
				f=0;
				break;
			}
		}
		if(f){
			cout<<v[n-1]-u[1]<<endl;
		}
	}
	return 0;
}
