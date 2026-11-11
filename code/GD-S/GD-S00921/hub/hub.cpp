#include<iostream>
#include<cstring>
using namespace std;
const int N=2e6+5;
struct ff{
	int v,next;
}g[N*2];
int c,T,n,k,tot,head[N],dep[N],maxn,mx,mx2;
void init(){
	tot=0;
	maxn=0;
	mx=0;
	memset(head,0,sizeof head);
	memset(g,0,sizeof g);
}
void add(int u,int v){
	g[++tot]={v,head[u]};
	head[u]=tot;
}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	if(dep[u]>maxn){
		maxn=dep[u];
		mx=u;
	}
	for(int i=head[u];i;i=g[i].next){
		int v=g[i].v;
		if(v==fa) continue;
		dfs(v,u);
	}
} 
void dfs2(int u,int fa){
	dep[u]=dep[fa]+1;
	if(dep[u]>maxn){
		maxn=dep[u];
		mx2=u;
	}
	for(int i=head[u];i;i=g[i].next){
		int v=g[i].v;
		if(v==fa) continue;
		dfs2(v,u);
	}
} 
void solve(){
	init();
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	maxn=0;
	dep[mx]=0;
	dfs2(mx,0);
	cout<<dep[mx2]-1<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
}
