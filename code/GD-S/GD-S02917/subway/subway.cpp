#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N],k,vis[N],dis[N];
vector<pair<int,int>> e[N];
int dist(int x,int y){
	priority_queue<int,vector<int>,greater<int>> q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push(x);
	dis[x]=0;
	vis[x]=0;
	while (!q.empty()){
		int cur=q.top();
		q.pop();
		vis[cur]=1;
		for (auto i:e[cur]){
			dis[i.first]=min(dis[i.first],dis[cur]+i.second);
			q.push(i.first);
		}
	}
	return dis[y];
	
}
signed main(){
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[N];
	}
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=k;j++){
			int u,v;
			cin>>u>>v;
			e[u].push_back({m+i,v});
		}
	}
	for (int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dist(x,y)<<endl;
	}
	
}
