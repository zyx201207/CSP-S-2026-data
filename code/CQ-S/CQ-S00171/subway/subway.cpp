#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+10,maxm=5e5+10;
int c,n,m,d,q,w[maxm],h[505],x,y;
long long dis[maxn];bool vis[maxn];
struct node{int x,data;};
vector<node>g[maxn];
int dijkstra(int x,int y){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	for(int i=1;i<=m+n*m;i++)dis[i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;dis[x]=0;pq.push({0,x});
	while(!pq.empty()){
		int tmp=pq.top().second;pq.pop();
//		cout<<tmp<<"\n";
		if(tmp==y)return dis[y];
		if(vis[tmp])continue;vis[tmp]=1;
		for(int i=0;i<g[tmp].size();i++){
			if(dis[g[tmp][i].x]>dis[tmp]+g[tmp][i].data){
				dis[g[tmp][i].x]=dis[tmp]+g[tmp][i].data;
				pq.push({dis[g[tmp][i].x],g[tmp][i].x});
			}
		}
	}
	return 0;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>h[j]>>x;
			g[h[j]].push_back({h[j]+i*m,x});
			g[h[j]+i*m].push_back({h[j],x});
		}
		for(int j=1;j<k;j++){
			g[h[j]+i*m].push_back({h[j+1]+i*m,0});
			g[h[j+1]+i*m].push_back({h[j]+i*m,0});
		}
	}
//	for(int i=1;i<=m+n*m;i++){
//		cout<<i<<":";
//		for(int j=0;j<g[i].size();j++)cout<<g[i][j].x<<" ";
//		cout<<"\n";
//	}
	while(q--){cin>>x>>y;cout<<dijkstra(x,y)+w[x]+w[y]<<"\n";}
	return 0;
}



/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/ 



