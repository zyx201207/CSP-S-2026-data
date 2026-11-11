#include <bits/stdc++.h>
//#define int long long
using namespace std;

const long long inf=102030405060708;
const int maxn=510;
const int maxm=500010;
const int maxj=20;
vector<pair<int,int>> adj[maxm+maxn],adj2[maxm];
struct state{
	int node;long long step;
	state(){}
	state(int a,long long b){node=a;step=b;}
};
struct comparer{
	bool operator()(const state& x,const state& y){
		return x.step>y.step;
	}
};
priority_queue<state,vector<state>,comparer> pq;
bool visited[maxm+maxn];
long long dist[maxm+maxn],length[maxm];
bool spj_A_flag;
int jump[maxm][maxj];
int w[maxm],depth[maxm];
int c,n,m,d,q;

void input(){
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	spj_A_flag=1;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;scanf("%d",&k);
		if(k>=3)spj_A_flag=0;
		if(k==1){
			int zt,nt;scanf("%d %d",&zt,&nt);
			continue;
		}
		vector<pair<int,int>> V;
		for(int j=1;j<=k;j++){
			int zt,nt;scanf("%d %d",&zt,&nt);
			adj[zt].push_back({m+i,nt});
			adj[m+i].push_back({zt,nt});
			V.push_back({zt,nt});
		}
		if(spj_A_flag){
			adj2[V[0].first].push_back({V[1].first,V[0].second+V[1].second});
			adj2[V[1].first].push_back({V[0].first,V[0].second+V[1].second});
		}
	}
}
void build_tree(int fa,int node){
	jump[node][0]=fa;
	depth[node]=depth[fa]+1;
	for(int i=0;i<(int)adj2[node].size();i++){
		int to=adj2[node][i].first,lw=adj2[node][i].second;
		if(to!=fa){
			length[to]=length[node]+lw;
			build_tree(node,to);
		}
	}
}
void init_jump(){
	for(int j=1;j<=19;j++){
		for(int i=1;i<=n;i++){
			jump[i][j]=jump[jump[i][j-1]][j-1];
		}
	}
}
int LCA(int x,int y){
	if(depth[x]<depth[y])swap(x,y);
	for(int i=19;i>=0 && depth[x]>depth[y];i--){
		if(depth[jump[x][i]]>=depth[y])x=jump[x][i];
	}
	if(x==y)return x;
	for(int i=19;i>=0;i--){
		if(jump[x][i]!=jump[y][i]){
			x=jump[x][i];
			y=jump[y][i];
		}
	}
	return jump[x][0];
}
long long p2dist(int x,int y){
	return length[x]+length[y]-2*length[LCA(x,y)];
}
long long sps_A(int x,int y){
	return w[x]+w[y]+p2dist(x,y);
}
void init(){
	for(int i=1;i<=m+n;i++){
		dist[i]=inf;
		visited[i]=0;
	}
}
long long isolve(int x,int y){
	init();
	dist[x]=0;
	pq.push(state(x,0));
	while(!pq.empty()){
		state fr=pq.top();pq.pop();
		if(visited[fr.node])continue;
		visited[fr.node]=1;
		for(int i=0;i<(int)adj[fr.node].size();i++){
			int to=adj[fr.node][i].first,lw=adj[fr.node][i].second;
			if(dist[fr.node]+lw < dist[to]){
				dist[to]=dist[fr.node]+lw;
				pq.push(state(to,dist[to]));
			}
		}
	}
	return dist[y]+w[x]+w[y];
}
void LunAsk(){
	for(int i=1;i<=q;i++){
		int x,y;scanf("%d %d",&x,&y);
		if(spj_A_flag){
			printf("%lld\n",sps_A(x,y));
		}else{
			printf("%lld\n",isolve(x,y));
		}
	}
}
void solve(){
	if(spj_A_flag){
		build_tree(0,1);
		init_jump();
		LunAsk();
	}else{
		LunAsk();
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	input();
	solve();
	return 0;
}
/*
that force code can pass 1~8 + 12~15(sum for 48) ok

for spcial A
because ki <= 2
//so the graph turn into a tree -> fake
f * k 

for spcial B
// how can we do???
we can get 12 FEN from it

for c==20 || c==21
because n==2
so every situation at most 2 subway
we can get 8 FEN from it

*/









/*
I'm so tired...
at 17:43

expect to get 48 FEN
*/
