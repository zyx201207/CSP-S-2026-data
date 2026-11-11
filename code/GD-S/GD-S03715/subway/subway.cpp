#include<set>
#include<queue>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;
const int N=505,M=5e5+5,T=2*M+N+25;
int c,n,m,D,q;
long long w[M]; //站口到站厅
int idx;
int blg[M]; //每个站站厅所属编号
struct node{
	int v,w;
};
vector<node> g[T];
void link(int u,int v,int w){
//	cout<<u<<"<->"<<v<<":"<<w<<endl;
	g[u].push_back((node){v,w});
	g[v].push_back((node){u,w});
}
int fa[T][21],dep[T]; //fa:0-20
long long dis[T]; 
bool vis[T];
void dfs1(int u,int f){
	vis[u]=1;
	fa[u][0]=f;
	dep[u]=dep[f]+1;
	for(int i=1;i<20;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(node j:g[u]){
		int v=j.v,w=j.w;
		if(v==f||vis[v])continue;
		dis[v]=dis[u]+w;
		dfs1(v,u);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int d=dep[u]-dep[v];
	for(int i=0;d;i++){
		if(d&1)u=fa[u][i];
		d>>=1;
	}
	if(u==v)return u;
	for(int i=19;i>=0;i--){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];
}
long long ans[100005]; //第i个问题答案
long long d[T];
struct stq{
	int num;
	long long val;
	bool operator < (stq a) const{
		return val>a.val;
	}
};
void Dij(int st){
	memset(vis,0,sizeof vis);
	memset(d,127,sizeof d);
	d[st]=0;
	priority_queue<stq> Q;
	Q.push({st,0});
	while(!Q.empty()){
		int u=Q.top().num;
		Q.pop();
		vis[u]=1;
		for(node j:g[u]){
			int v=j.v,w=j.w;
			if(vis[v])continue;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				Q.push({v,d[v]});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>D>>q;
	idx=n;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int stn,ti;
			cin>>stn>>ti;
			if(!blg[stn])blg[stn]=++idx;
			link(blg[stn],++idx,ti);
			link(idx,i,0);
		}
	}
	if(c<=11){
		vector<node> ques[1005];
		set<int> s;
		for(int i=1;i<=q;i++){
			int u,v;
			cin>>u>>v;
			s.insert(u);
			ques[u].push_back({v,i});
		}
		for(int u:s){
			Dij(blg[u]);
			for(node j:ques[u]){
				ans[j.w]=d[blg[j.v]]+w[u]+w[j.v];
			}
		}
		for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
		return 0;
	}
	dfs1(1,0);
	while(q--){
		int u,v;
		cin>>u>>v;
		long long tmp=w[u]+w[v];
		u=blg[u],v=blg[v];
		cout<<dis[u]+dis[v]-2*dis[lca(u,v)]+tmp<<endl;
	}
}
