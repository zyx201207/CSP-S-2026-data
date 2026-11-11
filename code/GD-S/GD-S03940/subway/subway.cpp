#include<bits/stdc++.h>
using namespace std;
int n,m,d,k,tot,a[500005],vis[500005];
long long dist[1000005];
unordered_map<int,pair<int,int>>mp;
vector<pair<int,int>>g[500005];
queue<int>q;
long long spfa(int s,int t){
	fill(dist+1,dist+tot+1,1e18);
	memset(vis,0,sizeof vis);
	q.push(s);
	dist[s]=a[s];
	while(q.size()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(auto p:g[u]){
			int v=p.first,w=p.second;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return dist[t]+a[t];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>k;
	tot=m;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int t,u,w,id;
		cin>>t;
		for(int j=0;j<t;j++){
			cin>>u>>w;
			int v=++tot;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
			if(j){
				g[v-1].push_back({v,0});
				g[v].push_back({v-1,0});
			}
		}
	}
	while(k--){
		int s,t;
		cin>>s>>t;
		cout<<spfa(s,t)<<"\n";
	}
	return 0;
}
