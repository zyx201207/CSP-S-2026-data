#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e6+1,Inf=0x3f3f3f3f;
__inline void read(int&x){
	char ch=getchar();
	x=0;
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch))
		x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return;
}
__inline void write(int x){
	if(x>=10){
		write(x/10);
		x%=10;
	}
	putchar(x^48);
	return;
}
__inline void writeln(int x){
	write(x);
	putchar('\n');
	return;
}
int Id,T,n,k,ans=Inf,dep[N],g[N][20],pl[N];
vector<int>e[N];
vector<array<int,2> >edges;
void init(){
	for(int j=1;j<20;j++)
		for(int i=1;i<=n;i++)
			g[i][j]=g[g[i][j-1]][j-1];
	return;
}
int qlca(int u,int v){
	if(dep[u]<dep[v])
		swap(u,v);
	for(int i=19;i>=0;i--)
		if(dep[g[u][i]]>=dep[v])
			u=g[u][i];
	for(int i=19;i>=0;i--)
		if(g[u][i]!=g[v][i])
			u=g[u][i],v=g[v][i];
	return u==v?u:g[v][0];
}
bool check(){
	int ecnt=0;
	for(auto ed:edges){
		int u=ed[0],v=ed[1];
		if(pl[u]&&pl[v])
			ecnt++;
	}
	return ecnt>=k-2;
}
void dtree(int u,int fath){
	dep[u]=dep[fath]+1,g[u][0]=fath;
	for(auto v:e[u]){
		if(v==fath)
			continue;
		dtree(v,u);
	}
	return;
}
vector<int>vec;
int qdis(int u,int v){
	int lca=qlca(u,v);
	return dep[u]+dep[v]-2*dep[lca];
}
void dfs(int stp,int cnt){
	if(cnt>k)
		return;
	if(stp>n){
		if(cnt<k||!check())
			return;
		int ret=0;
		for(int i=1,d;i<=n;i++){
			d=Inf;
			for(auto pt:vec){
				d=min(d,qdis(i,pt));
			}
			ret=max(ret,d);
		}
		ans=min(ans,ret);
		return;
	}
	pl[stp]=1;
	vec.push_back(stp);
	dfs(stp+1,cnt+1);
	pl[stp]=0;
	vec.pop_back();
	dfs(stp+1,cnt);
	return;
}
void clear(){
	for(int i=1;i<=n;i++)
		e[i].clear();
	edges.clear();
	ans=Inf;
	return;
}
void task(){
	clear();
	read(n),read(k);
	for(int i=1,u,v;i<n;i++){
		read(u),read(v);
		e[u].push_back(v),e[v].push_back(u);
		edges.push_back({u,v});
	}
	dtree(1,0),init();
	dfs(1,0);
	return writeln(ans);
}
string program(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(0);
	for(read(Id),read(T);T;T--)
		task();
	return"H17"; 
}
string H17=program();
signed main(){
	return 0;
}
