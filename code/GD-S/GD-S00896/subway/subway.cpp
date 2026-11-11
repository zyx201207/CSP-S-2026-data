#include <bits/stdc++.h>
using namespace std;
struct node{
	int u,dis;
	bool operator < (const node &x) const{
		return dis>x.dis;
	}
};
struct edg{
	int v,w;
};
bool vis[500010];
vector<edg> g[520];
int w[100010],a[500010],t[510][500010],k[500010],dis[500010];
int c, n, m, d, q;
void dijiastra(int s){
	for(int i=1;i<=m;i++) {
		dis[i]=1e9;
	}
	priority_queue<node> q;
	q.push({s,w[s]});
	dis[s]=w[s];
	while(!q.empty()){
		node e=q.top();
		q.pop();
		int u=e.u;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto t:g[u]){
			int v=t.v,w=t.w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>a[j]>>t[i][j];
			if(j>=2){
				g[a[j-1]].push_back({a[j],t[i][j]});
				g[a[j]].push_back({a[j-1],t[i][j-1]});
			}
		}
	} 
	
	while(q--){
		int x,y;
		cin>>x>>y;
		dijiastra(x);
		cout<<dis[y]+w[y];
	}
	return 0;
}
