#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int MAXN=505;
const int MAXM=5e5+5;
const int MAXD=25;
int c,n,m,d,q,w[MAXM],cnt;
struct node{
	int fi,se;
}a[MAXM];
vector<node>e[MAXM];
void add(int u,int v,int w){
	e[u].push_back({v,w});
	e[v].push_back({u,w});
}
bool operator<(const node&a,const node&b){
	return a.se>b.se;
}
int di[MAXM];
int dij(int s,int t){
	priority_queue<node>qq;
	bool vis[MAXM];
	memset(vis,0,sizeof(vis));
	memset(di,0x3f,sizeof(di));
	while(qq.size())qq.pop();
	qq.push({s,0});
	di[s]=0;
	while(qq.size()){
		int u=qq.top().fi;
		qq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].fi;
			int w=e[u][i].se;
			if(di[v]<=di[u]+w)continue;
			di[v]=di[u]+w;
			qq.push({v,di[v]});
		}
	}
	return di[t];
}
void solve1(){
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dij(a[x].fi,a[y].fi)<<"\n";
	}
}
int bfs(int s,int t){
	queue<int>qq;
	int k=0;
	bool vis[MAXM];
	memset(di,0,sizeof(di));
	memset(vis,0,sizeof(vis));
	qq.push(s);
	while(qq.size()){
		int u=qq.front();
		qq.pop();
		if(u==t)break;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].fi;
			k=e[u][i].se;
			if(vis[v])continue;
			di[v]=di[u]+1;
			qq.push(v);
		}
	}
	return di[t]*k;
}
void solve2(){
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<bfs(a[x].se,a[y].se)+w[x]+w[y]<<"\n";
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		a[i]={++cnt,++cnt};
		add(a[i].fi,a[i].se,w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int t=++cnt;
		while(k--){
			int x,y;
			cin>>x>>y;
			add(t,a[x].se,y);
		}
	}
	if(c>=1&&c<=6)solve1();
	else if(c>=12&&c<=15)solve2();
	else solve1();
	return 0;
}
/*
T2 subway
1~6 全源最短路
12~15 每次询问暴力bfs
20~21 图特殊 不会 
48pts -8pts
*/ 
