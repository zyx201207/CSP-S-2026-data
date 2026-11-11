#include<bits/stdc++.h>

using namespace std;
int dist[50005],w[50005],a[50005][50005],c,n,m,d,q,t[5005][5005],o;
vector<int>g[50005];
void bfs(int node){
	memset(dist,0x3f,sizeof(dist));
	queue<int>q;
	dist[node]=0;
	q.push(node);
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(dist[v]>dist[u]+1){
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
}
signed main(){
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
			if(j&1){
				cin>>a[i][j];
				g[a[i][j]].push_back(a[i][j-1]);
				g[a[i][j-1]].push_back(a[i][j]);
			}
			else {
				cin>>t[i][j];
				o=t[i][j];
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		bfs(x);
		cout<<dist[y]*o+w[x]+w[y]<<endl;
	}
	return 0;
}
