#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,k,a,b;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(ll i=1;i<n;i++) cin>>a>>b;
		cout<<max(0ll,(n-1)/2-k/2)<<'\n';
	}
	return 0;
}
