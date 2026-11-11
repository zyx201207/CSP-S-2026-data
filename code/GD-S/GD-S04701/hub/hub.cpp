#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t,n,k;
vector<vector<ll>> g;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	ll ans=0;
	while(t--){
		cin>>n>>k;
		g.assign(n+1);
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				
			}
		}
	}
	return 0;
}
