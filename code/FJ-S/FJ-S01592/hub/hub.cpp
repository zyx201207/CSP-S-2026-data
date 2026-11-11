#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,dis[1000006],sid[1000006];
vector<int> g[1000006]; 
void dfs(int p,int lst){
	dis[p]=0;
	for(auto x:g[p]){
		if(x==lst){
			continue;
		}
		dis[p]=min(dis[p],dis[x]);
	}
	dis[p]++;
	return;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		for(int i=1;i<=n;i++){
			dfs(i,-1);
			sid[i]=dis[i];
		}
		sort(sid+1,sid+n+1);
		cout<<sid[2]<<"\n";
		
	}
}/*
24pts
//freopen
ok
*/
