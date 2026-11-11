#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,ans=-1;
queue<int>q[1000000];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			q[u].push(v);
			q[v].push(u);
			ans=max(ans,abs(u-v));
		}
		cout<<ans<<endl;
	}
	return 0;
}
