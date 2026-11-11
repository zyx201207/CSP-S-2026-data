#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,n,d,q,w[50010];
int t[510][50010],m,a[510][50010],vis[500010],dis[500010];
struct node{
	int v,w;
	friend bool operator<(node x,node y){
		return x.w>y.w;
	}
};
vector<node>adj[500510];
void djist(int root){
	priority_queue<node>pq;
	memset(dis,0x3f,sizeof(dis));
	dis[root]=0;
	pq.push({root,dis[root]});
	memset(vis,0,sizeof(vis));
	while(pq.size()){
		int u=pq.top().v;
		pq.pop();
		//cout<<u<<" ";
		vis[u]=1;
		for(auto x:adj[u]){
			
			if(dis[x.v]>dis[u]+x.w){
				dis[x.v]=dis[u]+x.w;
				if(vis[x.v]==0){
					
					pq.push({x.v,dis[x.v]});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			adj[a[i][j]].push_back({m+i,t[i][j]});
			adj[m+i].push_back({a[i][j],t[i][j]});
		}
	}
	//lougu lele_88888
	while(q--){
		int x,y;
		cin>>x>>y;
		djist(x);
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
