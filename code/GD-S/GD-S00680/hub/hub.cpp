#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,maxn=0;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		maxn=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			maxn=max(maxn,u);
		}
		if(maxn<=n) cout<<1<<'\n';
		else cout<<maxn/n+1<<'\n';
	}
	return 0;
}
