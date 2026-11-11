#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,u,v;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>u>>v;
		cout<<max(0,(n+1)/2-k)<<'\n';
	}
	return 0;
}
