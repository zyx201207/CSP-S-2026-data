#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[10005];
struct qwe{
	int to,w;
};
vector<qwe> ve[50005];
int djst(int x,int y){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	long long vis[50005]={},dist[10005]={};
	memset(dist,1e6,sizeof(dist));
	dist[x]=0;
	vis[x]=0;
	for(int i=0;i<ve[x].size();i++)    q.push({ve[x][i].to,ve[x][i].w});
	while(!q.empty()){
		int t=q.top().first,o=q.top().second;
		q.pop();
		if(vis[t]==0){
			vis[t]=1;
			for(auto e:ve[t]){
				if(dist[e.to]>dist[t]+o){
					dist[e.to]=dist[t]+o;
					q.push({e.to,e.w});
				}
			}
		}
	}
	for(int i=1;i<=n;i++)    ve[i].clear();
	return (dist[y]>1e6)?a[y]:dist[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int s;
		cin>>s;
		int u,v,p1,p2,w;
		cin>>u>>p1>>v>>p2;
		w=p1+p2+a[u]+a[v];
		ve[v].push_back({u,w});
		ve[u].push_back({v,w});
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<djst(x,y)<<'\n';
	}
	return 0;
}

