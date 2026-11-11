#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
queue<int>sz[1000006];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>u>>v;
		sz[u].push(v);
		sz[v].push(u);
		
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
} 
