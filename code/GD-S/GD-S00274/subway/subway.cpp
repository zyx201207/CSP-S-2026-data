#include<bits/stdc++.h>
#define For(a,b,c) for(int a=b;a<=c;a++)
#define Fro(a,b,c) for(int a=b;a>=c;a--)
#define ms(a) memset(a,0,sizeof a)
#define int long long
#define Pii pair<int,int>
#define pb push_back
#define Fopen(in) freopen(in".in","r",stdin),freopen(in".out","w",stdout);
using namespace std;
constexpr int N=1e6+5,M=5e5+5,D=22;

int c,n,m,d,q,w[N],W[N],kk,k[N];
int dis[N],vis[N],ans[N];
map<int,map<int,int>> dfn;
struct Edge{
	int v,w;
};
struct Node{
	int v,w;
	bool operator<(const Node&b)const{return w>b.w;}
};
struct Query{
	int u,v,id;
	bool operator<(const Query&b)const{return u==b.u?v<b.v:u<b.u;}
}qry[N];
vector<Edge> g[N];
vector<int> a[N],t[N];
vector<Pii> e[N];
#define id(i,j) (i-1)*(kk)+(j)
void dijkstra(int u){
	priority_queue<Node> pq;
	pq.push({u,0});
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[u]=0;
	while(pq.size()){
		auto [u,tmp]=pq.top();pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto [v,w]:g[u]){
			if(dis[u]+w<dis[v])
				dis[v]=dis[u]+w,
				pq.push({v,dis[v]});
		}
	}
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	For(i,1,m)
		cin>>w[i];
	For(i,1,n){
		cin>>k[i];
		kk=max(kk,k[i]);
		For(j,1,k[i]){
			int u,v;
			cin>>u>>v;
			a[i].pb(u),t[i].pb(v);
			e[u].pb(Pii{i,v});
			dfn[i][u]=j;
			// cin>>a[i][j]>>t[i][j];
		}
	}
	// kk++;
	For(i,1,m)
		For(j,1,k[i]-1)
			g[id(i,j)].pb({id(i,j+1),0}),
			g[id(i,j+1)].pb({id(i,j),0});
	For(i,1,m)
		for(auto [ii,u]:e[i])
			for(auto [jj,v]:e[i])
				if(ii!=jj)
					g[id(ii,dfn[ii][i])].pb({id(jj,dfn[jj][i]),u+v});
	For(i,1,m)
		for(auto [ii,u]:e[i])
			W[id(ii,dfn[ii][i])]=w[i]+u;
	For(i,1,q){
		cin>>qry[i].u>>qry[i].v;
		qry[i].id=i;
	}
	sort(qry+1,qry+1+q);
	memset(ans,0x3f,sizeof ans);
	For(i,1,m){
		for(auto [ii,u]:e[i]){
			dijkstra(id(ii,dfn[ii][i]));
			For(_,1,q){
				if(qry[_].u==i){
					for(auto [jj,v]:e[qry[_].v]){
						ans[qry[_].id]=min(ans[qry[_].id],dis[id(jj,dfn[jj][qry[_].v])]+W[id(ii,dfn[ii][i])]+W[id(jj,dfn[jj][qry[_].v])]);
						// cerr<<qry[i].u<<" "<<qry[i].v<<" "<<dis[id(jj,dfn[jj][qry[i].v])]<<" "<<id(jj,dfn[jj][qry[i].v])<<' '<<W[id(ii,dfn[ii][i])]<<" "<<W[id(jj,dfn[jj][qry[i].v])]<<'\n';
					}
				}
			}
		}
	}
	For(i,1,q)
		cout<<ans[i]<<'\n';
}
signed main(){
	Fopen("subway")
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--)
		solve();
	return 0;  
}

// 神人题
// luogu uid 1210193 qwqwq sto Shellchen orz qwqqwq dsadsa 