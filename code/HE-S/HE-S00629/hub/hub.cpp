#include<bits/stdc++.h>
#define int long long 
#define pb push_back
using namespace std;
const int N=1e6+5;
int c,t;
int n,k,u,v;
vector<int> q[N];
struct node{
	int fi,se;
}e[N];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int xdsdg[65];
void write(int x){
	int tot=0;
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x==0){
		putchar('0');return;
	}
	while(x){
		xdsdg[++tot]=((x%10)^48);
		x/=10;
	}
	for(int i=tot;i;i--){
		putchar(xdsdg[i]);
	}
}
int ans[N],fa[N];
bool vis[N];
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	if((x=find(x))==(y=find(y)))return ;
	fa[x]=y;
}
bool check(){
	for(int i=1;i<=n;i++){
		vis[i]=0,fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		vis[ans[i]]=1;
	}
	for(int i=1;i<n;i++){
		int u=e[i].fi,v=e[i].se;
		if(vis[u]&&vis[v]){
			merge(u,v);
		}
	}
	int sum=0;
	for(int i=1;i<=k;i++){
		if(fa[ans[i]]==ans[i])++sum;
	}
	if(sum>2)return 0;
	else return 1;
}
int jing=N;
queue<node> p;
bool in[N];
int bfs(int s){
	while(!p.empty())p.pop();
	for(int i=1;i<=n;i++)in[i]=0;
	p.push({s,0});
	in[s]=1;
	
	while(!p.empty()){
		node now=p.front();p.pop();
		int to=now.fi;
//		if(vis[to])cout<<"^"<<s<<" "<<to<<'\n';
		if(vis[to])return now.se;
		for(int v:q[to]){
			if(!in[v]){
				p.push({v,now.se+1});
				in[v]=1;
			}
		}
	}
	
}
void dfs1(int x){
	if(x==k+1){
		if(check()){
//			cout<<"*";
//			for(int i=1;i<=k;i++)cout<<ans[i]<<' ';
//			cout<<"\n";
			int maxn=0;
			for(int i=1;i<=n;i++){
				if(vis[i])continue;
				maxn=max(maxn,bfs(i));
			}
			jing=min(jing,maxn);
		}
		return;
	}
	for(int i=ans[x-1]+1;i<=n;i++){
		ans[x]=i;
		dfs1(x+1);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();k=read();
		jing = N;
		for(int i=1;i<=n;i++)q[i].clear();
		for(int i=1;i<n;i++){
			u=read();v=read();
			e[i]={u,v};
			q[u].pb(v);q[v].pb(u);
		}
		dfs1(1);
		write(jing);
		putchar('\n');
	}
	return 0;
}
