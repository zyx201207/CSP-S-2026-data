#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k,ans;
		cin>>n>>k;
		int u,v; 
		for(int i=1;i<=n;i++){
			cin>>u>>v;
			if(i==2) ans=v;
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
