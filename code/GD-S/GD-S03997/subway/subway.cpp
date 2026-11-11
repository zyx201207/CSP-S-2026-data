#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int N=1500100;

int c,n,m,d,q;
int idx;
struct node{
	int to,w;
};
vector<node> e[N];

int f[N],fa[N],dep[N];
bool vis[N];

void dfs(int u){
	vis[u]=true;
	for(auto x:e[u]){
		int v=x.to,w=x.w;
	 	if(vis[v]) continue;
		fa[v]=u;
		f[v]=f[u]+w;
		dep[v]=dep[u]+1;
		dfs(v);
	}
}

// m: point n: line 
int p[N][22];
void init(){
	for(int i=1;i<=idx;i++) p[i][0]=fa[i];
	for(int i=1;i<=20;i++)
		for(int j=1;j<=idx;j++)
			p[j][i]=p[p[j][i-1]][i-1];
}

int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(dep[p[y][i]]>=dep[x]) y=p[y][i];
	for(int i=20;i>=0;i--) if(p[x][i]!=p[y][i]) x=p[x][i],y=p[y][i];
	return fa[x];
}

//again!

int f1[N],fa1[N],dep1[N];
bool vis1[N];

void dfs1(int u){
	vis1[u]=true;
	for(auto x:e[u]){
		int v=x.to,w=x.w;
		if(vis1[v]) continue;
		fa1[v]=u;
		f1[v]=f1[u]+w;
		dep1[v]=dep1[u]+1;
		dfs1(v);
	}
}

int p1[N][22];
void init1(){
	for(int i=1;i<=idx;i++) p1[i][0]=fa1[i];
	for(int i=1;i<=20;i++)
		for(int j=1;j<=idx;j++)
			p1[j][i]=p1[p1[j][i-1]][i-1];
}

int lca1(int x,int y){
	if(dep1[x]>dep1[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(dep1[p1[y][i]]>=dep1[x]) y=p1[y][i];
	for(int i=20;i>=0;i--) if(p1[x][i]!=p1[y][i]) x=p1[x][i],y=p1[y][i];
	return fa1[x];
}

signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	idx=m;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		++idx;
		e[idx].push_back({i,w});
		e[i].push_back({idx,w});
	}
	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			
			++idx;
			e[x+m].push_back({idx,y});
			e[idx].push_back({x+m,y});
			
			if(j==1) continue; 
			e[idx].push_back({idx-1,0});
			e[idx-1].push_back({idx,0});
		}
	}
	
	int rt=m+1;
	fa[rt]=rt;
	dfs(rt);
	init();
	
	rt=2*m-1;
	fa1[rt]=rt;
	dfs1(rt);
	init1();
	
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<min(f[x]+f[y]-2*f[lca(x,y)],f1[x]+f1[y]-2*f1[lca1(x,y)])<<"\n";
	}
	
	return 0;
}
/* 
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
