#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5E5+7;
const int M = 5E2+7;
const int TOT = N*22+M;
int c,n,m,q,cnt;
struct edge{
	int v,w;
};
vector<edge> g[TOT];
// µØÌú¿Ú 1~n
// Õ¾Ìü n+1~2*n 
void addedge(int u,int v,int w){
	g[u].push_back({v,w});
	g[v].push_back({u,w});
}
int d[N];
bool vis[TOT];
void spfa(int u){
	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	queue<int> q;
	q.push(u);
	d[u]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(edge e:g[u]){
			int v=e.v,w=e.w;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				if(!vis[v]){
					q.push(v);
					vis[v]=true;					
				}
			}
		}
	}
}
int ans[N];
struct query{
	int u,v,id;
}qry[N];
bool cmp(query a,query b){
	return a.u<b.u;
}
/*

int timme,dfn[TOT],low[TOT],back[TOT],st[TOT][20],dis[TOT],dep[TOT];
int loopcnt;
stack<pair<int,int>> stk;
vector<pair<int,int>> loop[TOT];
vector<int> s[TOT]; 
vector<pair<int,int>> bel[TOT];
void tarjan(int u,int fa,int w){
	stk.push({u,w});
	dfn[u]=low[u]=++timme;
	for(edge e:g[u]){
		int v=e.v,w=e.w;
		if(!dfn[v]){
			tarjan(v,u,w);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				loopcnt++;
				while(stk.top().first!=v){
					auto x=stk.top();
					stk.pop();
					loop[loopcnt].push_back(x);
				}
				auto x=stk.top();
				stk.pop();
				loop[loopcnt].push_back(x);
				loop[loopcnt].push_back({u,back[loop[loopcnt][0].first]});
			}
		}
		else if(v!=fa){
			low[u]=min(low[u],dfn[v]);
			back[u]=w;
		}
	}
}
int find
void dfs(int u,int fat){
	fa[u][0]=fat;
	for(int j=1;j<=20;j++) fa[u][j]=fa[fa[u][j-1]][j-1];
	if(u<=tot&&fat){
		dis[u]=dis[fa[u][1]];
		int id=fat-tot,p1,p2;
		for(auto p:bel[u]){
			p.id
		}
	}
}
void init(){
	for(int i=1;i<=loopcnt;i++){
		if(loop[i].size()==2) loop[i][1].second=loop[i][0].second;
		s[i].push_back(0);
		for(int j=1;j<loop[i].size();j++){
			s[i].push_back(s[i][s[i].size()-1]+loop[i][j-1].second);
		}
		for(int j=0;j<loop[i].size();j++){
			bel[loop[i][j].first].push_back({i,j});
			e[loop[i][j].first].push_back(tot+i);
			e[tot+i].push_back(loop[i][j].first);
		}
	}
}
*/
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> m >> n >> q >> q;
	for(int i=1;i<=n;i++){
		int w;
		cin >> w;
		addedge(i,i+n,w);
	}
	int tot=2*n;
	for(int i=1;i<=m;i++){
		int k;
		cin >> k;
		int mid=++tot;
		for(int i=1;i<=k;i++){
			int u,w;
			cin >> u >> w;
			addedge(u+n,++tot,w);
			addedge(tot,mid,0);
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin >> u >> v;
		if(u>v) swap(u,v);
		qry[i]={u,v,i};
	}
	sort(qry+1,qry+1+q,cmp);
	for(int i=1;i<=q;i++){
		if(qry[i].u!=qry[i-1].u){
			spfa(qry[i].u);
		}
		ans[qry[i].id]=d[qry[i].v];
	}
	for(int i=1;i<=q;i++) cout << ans[i] << '\n';
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/ 
