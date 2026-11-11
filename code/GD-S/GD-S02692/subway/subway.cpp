#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q,sc;
vector<pair<int,int>> su[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	if(c<=11){
		int w[m+1]; 
		vector<pair<int,int>> e[m+1];
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>sc;
			int a1[sc],t1[sc];
			for(int j=0;j<sc;j++){
				cin>>a1[j]>>t1[j];
			}
			for(int j=0;j<sc;j++){
				for(int k=0;k<j;k++){
					if(j==k) continue;
					e[a1[j]].push_back({a1[k],t1[j]+t1[k]});
					e[a1[k]].push_back({a1[j],t1[j]+t1[k]});
				}
			}
		}
		while(q--){
			int xr,yr;
			int dis[m+1],vis[m+1];
			memset(vis,0,sizeof(vis));
			fill(dis,dis+m+1,2e9);
			cin>>xr>>yr;
			dis[xr]=0;
			priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
			q.push({0,xr});
			while(!q.empty()){
				int u=q.top().second; q.pop();
				if(vis[u]) continue;
				vis[u]=1;
				for(auto &o:e[u]){
					int w=o.second,v=o.first;
					if(dis[v]>dis[u]+w) dis[v]=dis[u]+w,q.push({dis[v],v});
				}
			}
			cout<<dis[yr]+w[xr]+w[yr]<<'\n';
		}
	}
	return 0;
}
