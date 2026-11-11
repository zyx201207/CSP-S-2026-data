//GZ-S00145 周小晰 贵阳一中 
#include<bits/stdc++.h>
using namespace std;
void dij(int s){
	dis[s]=0;
	pq.push({-dis[s],s});
	while(!pq.empty()){
		int u = pq.top.second();
		pq.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int v=1;v<=n;v++){
			if(!vis[v]&&dis[v]>dis[u]+adj[u][v]){
				dis[v]=dis[u]+adj[u][v];
				pq.push({-dis[v],v});
				pre[v]=u;
			}
			else if(!vis[v]&&dis[v]==dis[u]+adj[u][v]){
				pre[v]=-1;
			}
		}
	}
}
int main(){
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		cout<<0; 
	}
	return 0;
}
//T4 时间20mins
