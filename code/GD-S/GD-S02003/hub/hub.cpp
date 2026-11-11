#include<bits/stdc++.h>
#define int long long

using namespace std;

int c,t;
int n,k;

signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
		}
		if(n-k>k)cout<<1<<'\n';
		else cout<<0<<'\n';	
	}
	return 0;
}
