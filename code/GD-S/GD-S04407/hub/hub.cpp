#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace FastIO{
	template<class T>
	T read(T&x){
		x=0;bool f=false;char ch=getchar();
		while(!isdigit(ch)) f|=!(ch^'-'),ch=getchar();
		while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch&0xF),ch=getchar();
		if(f) x=-x;return x;
	}
	template<class T>
	void write(T x,char ch=' '){
		if(x<0) putchar('-'),x=-x;
		int cnt=0;char tmp[41];
		while(x>9) tmp[cnt++]=x%10+'0',x/=10;tmp[cnt++]=x+'0';
		while(cnt) putchar(tmp[--cnt]);putchar(ch);
	}
}
using namespace FastIO;
const int N=1e3+10;
struct disjoit_set_union{
	int fa[N],n;
	void init(int _n){
		n=_n;
		for(int i=1;i<=n;i++) fa[i]=i;
	}
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	inline void merge(int x,int y){fa[find(x)]=find(y);}
}S;
struct chain_forward_star{int nxt,to;}edge[N<<1];
int dis[N][N],head[N],Tid,T,n,K,cnt,ans=0x3f3f3f3f,ecnt,root;
int pos[N];
bool vis[N];
inline void add(int u,int v){edge[++ecnt]={head[u],v},head[u]=ecnt;}
void solve(){
	cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) pos[++cnt]=i;
	}
	S.init(n);
	for(int i=1;i<=cnt;i++){
		for(int j=i+1;j<=cnt;j++){
			if(dis[pos[i]][pos[j]]==1) S.merge(pos[i],pos[j]);
		}
	}
	int tot=0;
	for(int i=1;i<=cnt;i++) tot+=(pos[i]==S.fa[pos[i]]);
	if(tot>2) return;
	int d=0;
	for(int i=1;i<=n;i++){
		int minn=0x3f3f3f3f;
		for(int j=1;j<=cnt;j++) minn=min(minn,dis[i][pos[j]]);
		d=max(d,minn);
	}
	ans=min(ans,d);
}
void Dfs(int u,int pre){
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v!=pre) dis[root][v]=dis[root][u]+1,Dfs(v,u);
	}
}
void dfs(int x,int k){
	if(k==K){
		solve();
		return;
	}
	if(k>K) return;
	if(k+n-x+1<K) return;
	if(x>n) return;
	vis[x]=true;
	dfs(x+1,k+1);
	vis[x]=false;
	dfs(x+1,k);
}
void work(){
	read(n),read(K);
	for(int x,y,t=n;--t;){
		read(x),read(y);
		add(x,y),add(y,x);
	}
	ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++) root=i,Dfs(i,0);
	dfs(1,0);
	write(ans,'\n');
	ecnt=0;
	for(int i=1;i<=n;i++) head[i]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	read(Tid),read(T);
	while(T--) work();
	
	fclose(stdin);fclose(stdout);
	return 0;
}
