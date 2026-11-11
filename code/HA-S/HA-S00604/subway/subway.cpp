#include<bits/stdc++.h>
using namespace std;
int w[500005];
struct edge{
	int v,w;
};
struct point{
	int u,w;
};
bool operator <(point a,point b){
	return a.w>b.w;
}
vector<edge>g[500505];
bool vis[1505];
int dij(int s,int e){
	priority_queue<point>q;
	q.push({s,0});
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
		point now=q.top();
		q.pop();
		//cout<<now.u<<' '<<now.w<<endl;
		//if(now.w==22)return 0;
		if(now.u==e)return now.w;
		for(auto nxt:g[now.u]){
			if(!vis[nxt.v]){
				q.push({nxt.v,nxt.w+now.w});
				vis[nxt.v]=1;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(c>=9){
			int v1,w1,v2,w2;
			if(x==2){
				cin>>v1>>w1>>v2>>w2;
				g[v1].push_back({v2,w1+w2});
				g[v2].push_back({v1,w1+w2});
			}
		}
		else for(int j=0;j<x;j++){
			int v,w;
			cin>>v>>w;
			g[1000+i].push_back({v,w});
			g[v].push_back({1000+i,w});
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		cout<<w[s]+w[e]+dij(s,e)<<endl;
	}
	return 0;
}
