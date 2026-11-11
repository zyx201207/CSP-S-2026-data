#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int maxn=2000010;
const int maxj=23;
deque<int> choice;
int jump[maxn][maxj];
int depth[maxn],F[maxn];
bool choiced[maxn];
vector<pair<int,int>> edges;
vector<int> adj[maxn];
int n,k,ans;
int c,t;

void input(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d %d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.push_back({u,v});
	}
}
void build_tree(int fa,int node){
	depth[node]=depth[fa]+1;
	jump[node][0]=fa;
	for(int i=0;i<(int)adj[node].size();i++){
		int to=adj[node][i];
		if(to!=fa){
			build_tree(node,to);
		}
	}
}
void init_jump(){
	for(int j=1;j<=21;j++){
		for(int i=1;i<=n;i++){
			jump[i][j]=jump[jump[i][j-1]][j-1];
		}
	}
}
int LCA(int x,int y){
	if(depth[x]<depth[y])swap(x,y);
	for(int i=21;i>=0 && depth[x]>depth[y];i--){
		if(depth[jump[x][i]]>=depth[y])x=jump[x][i];
	}
	if(x==y)return x;
	for(int i=21;i>=0;i--){
		if(jump[x][i]!=jump[y][i]){
			x=jump[x][i];
			y=jump[y][i];
		}
	}
	return jump[x][0];
}
int dist(int a,int b){
	return depth[a]+depth[b]-2*depth[LCA(a,b)];
}
void init_fa(){
	for(int i=1;i<=n;i++){
		F[i]=i;
	}
}
int find(int x){return (F[x]==x?x:F[x]=find(F[x]));}
void megre(int x,int y){int fx=find(x),fy=find(y);F[fx]=F[fy];}
void make_mark(){
	for(int i=0;i<k;i++){
		choiced[choice[i]]=1;
	}
}
bool ltk_judge(){
	init_fa();
	int ltkn=k;
	for(int i=0;i<n-1 && ltkn>=2;i++){
		int U=edges[i].first,V=edges[i].second;
		if(choiced[U] && choiced[V] && find(U)!=find(V)){
			megre(U,V);
			ltkn--;
		}
	}
	return ltkn<=2;
}
void updata_ans(){
	int mxv=0;
	for(int i=1;i<=n;i++){
		int miv=maxn;
		for(int j=0;j<k;j++){
			miv=min(miv,dist(i,choice[j]));
		}
		mxv=max(mxv,miv);
	}
	ans=min(ans,mxv);
}
void clear_mark(){
	for(int i=0;i<k;i++){
		choiced[choice[i]]=1;
	}
}
void choose(int pl){
	if(pl==k+1){
		make_mark();
		if(ltk_judge()){
			updata_ans();
		}
		clear_mark();
		return;
	}
	//if(n-choice.back()+1>=k-pl){
	//	return;
	//}
	int basez=(choice.size()==0?0:choice.back());
	for(int i=basez+1;i<=n;i++){
		choice.push_back(i);
		choose(pl+1);
		choice.pop_back();
	}
}
void solve(){
	build_tree(0,1);
	init_jump();
	ans=maxn;
	choose(1);
}
void output(){
	printf("%d",ans);
}
void clear(){
	while(!choice.empty())choice.pop_back();
	edges.clear();
	for(int i=1;i<=n;i++){
		adj[i].clear();
		depth[i]=0;
		for(int j=0;j<=21;j++){
			jump[i][j]=0;
		}
	}
}
void LunAsk(){
	scanf("%d %d",&c,&t);
	for(int i=1;i<=t;i++){
		input();
		solve();
		output();
		clear();
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	LunAsk();
	return 0;
}









/*
I'm so tired...
at 17:07

expect to get 0 or 4 FEN
*/
