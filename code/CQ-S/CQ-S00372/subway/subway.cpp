#include<bits/stdc++.h>
#define int long long
using namespace std;
int lingci[1000005]={};
vector<vector<pair<int,int> > > tu;
int dist[1505][1505]={};
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > dui;
bool b[1505]={};
int _=0,n=0,T=0;
void dijkstra(int start){
	memset(b,0,sizeof(b));
	memset(dist[start],127,sizeof(dist[start]));
	while(!dui.empty()) dui.pop();
	dist[start][start]=0;
	dui.push(make_pair(dist[start][start],start));
	while(!dui.empty()){
		int u=dui.top().second;
		dui.pop();
		if(b[u]) continue;
		b[u]=1;
		for(int i=0;i<tu[u].size();i++){
			int v=tu[u][i].first,w=tu[u][i].second;
			if(dist[start][v]>dist[start][u]+w){
				dist[start][v]=dist[start][u]+w;
				if(!b[v]) dui.push(make_pair(dist[start][v],v));
			}
		}
	}
}
bool b_bfs[1000005]={};
int dist_bfs[1000005]={};
queue<int> duilie;
void bfs(int start){
	for(int i=1;i<=_+n;i++) b_bfs[i]=dist_bfs[i]=0;
	while(!duilie.empty()) duilie.pop();
	duilie.push(start);
	b_bfs[start]=1;
	while(!duilie.empty()){
		int u=duilie.front();
		duilie.pop();
		for(int i=0;i<tu[u].size();i++){
			int v=tu[u][i].first,w=tu[u][i].second;
			if(!b_bfs[v]){
				dist_bfs[v]=dist_bfs[u]+w;
				duilie.push(v);
				b_bfs[v]=1;
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&_,&_,&n,&T,&T);
	tu.resize(_+n+5);
	for(int i=1;i<=n;i++){
		scanf("%lld",&lingci[i]);
	}
	for(int i=1;i<=_;i++){
		int wenhao=0;
		scanf("%lld",&wenhao);
		while(wenhao--){
			int u,w;
			scanf("%lld%lld",&u,&w);
			tu[u].push_back(make_pair(n+i,w));
			tu[n+i].push_back(make_pair(u,w));
		}
	}
	if(n<=1005){
		for(int i=1;i<=n;i++){
			dijkstra(i);
		}
		while(T--){
			int u=0,v=0;
			scanf("%lld%lld",&u,&v);
			printf("%lld\n",lingci[u]+dist[u][v]+lingci[v]);
		}
		return 0;
	}
	else{
		while(T--){
			int u=0,v=0;
			scanf("%lld%lld",&u,&v);
			bfs(u);
			printf("%lld\n",lingci[u]+dist_bfs[v]+lingci[v]);
		}
		return 0;
	}
}
