#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 5e5+5;
vector<pair<int,int>>graph[MAXN];
int ex[MAXN];
int c,n,m,d,q;
int fa[MAXN];
struct edge{
	int f;
	int t;
	int w;
}e[MAXN];
int ecnt;
bool cmp(edge a,edge b){
	return a.w<b.w;
}

int find(int x){
	if(x!=fa[x])fa[x] = find(fa[x]);
	return fa[x];
}

void merge(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx==fy)return;
	fa[fx] = fy;
	return;
}

int anc[MAXN][20];
int depth[MAXN];
void dfs(int u,int fa){
	depth[u] = depth[fa]+1;
	anc[u][0] = fa;
	for(int i = 1;i<20;i++){
		anc[u][i] = anc[anc[u][i-1]][i-1];
	}
	for(auto e:graph[u]){
		int v = e.first;
		if(v==fa)continue;
		dfs(v,u);
	}
	return;
}

int LCA(int x,int y){
	if(depth[x]<depth[y]){
		swap(x,y);
	}
	if(depth[x]!=depth[y]){
		for(int i = 19;i>=0;i--){
			if(depth[anc[x][i]]<depth[y])continue;
			x = anc[x][i];
		}
	}
	if(x==y)return x;
	for(int i = 19;i>=0;i--){
		if(anc[x][i]==anc[y][i])continue;
		x = anc[x][i];
		y = anc[y][i];
	}
	return anc[y][0];
}

int main(){
	int k;
	int x,y;
	int ox,oy;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>ex[i];
		fa[i] = i;
	}
	for(int i = 1;i<=n;i++){
		cin>>k;
		cin>>ox>>oy;
		for(int j = 2;j<=k;j++){
			cin>>x>>y;
			e[++ecnt] = {ox,x,oy+y};
		}
	}
	sort(e+1,e+ecnt+1,cmp);
	for(int i = 1;i<=ecnt;i++){
		if(find(e[i].f)==find(e[i].t))continue;
		merge(e[i].f,e[i].t);
		graph[e[i].f].push_back({e[i].t,e[i].w});
		graph[e[i].t].push_back({e[i].f,e[i].w});
	}
	for(int i = 1;i<=q;i++){
		cin>>x>>y;
		int l = LCA(x,y);
		cout<<ex[x]+ex[y]+l<<"\n";
	}
	return 0;
}
