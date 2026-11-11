#include<iostream>
#define int long long
using namespace std;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int ans=0;
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			if(i%t==0) ans=u;
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
