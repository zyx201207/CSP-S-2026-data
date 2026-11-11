#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
ll c,t,n,k,a,b;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(ll i=1;i<n;++i) cin>>a>>b;
		if(k>1) cout<<k-1<<"\n";
		else cout<<k<<"\n";
	}
	
	return 0;
}
