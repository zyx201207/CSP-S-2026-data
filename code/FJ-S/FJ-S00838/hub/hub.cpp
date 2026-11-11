#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
inline int read(){
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int x=0;
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
inline ll readll(){
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	ll x=0;
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
void put(int x){
	if(x>9) put(x/10);
	putchar((x%10)^48);
}
void putll(ll x){
	if(x>9) putll(x/10);
	putchar((x%10)^48);
}
int c,T,n,k;
int head[N],nxt[N<<1],ver[N<<1],tot;
int fa[N][20],dep[N],mn[N][20],lg[N];
int dfn[N],rnk[N],cnt;
inline void add(int u,int v){
	ver[++tot]=v,nxt[tot]=head[u],head[u]=tot;
	ver[++tot]=u,nxt[tot]=head[v],head[v]=tot;
}
void dfs(int u){
	dfn[u]=++cnt;rnk[cnt]=u;dep[u]=dep[fa[u][0]]+1;
	for(int i=head[u];i;i=nxt[i]){
		int v=ver[i];
		if(fa[u][0]==v) continue;
		fa[v][0]=u,dfs(v);
	}
}
inline int ask(int l,int r){
	int k=lg[r-l+1];
	return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
inline int slca(int u,int v){
	if(u==v) return u;
	u=dfn[u],v=dfn[v];
	if(u>v) swap(u,v);
	return rnk[ask(u+1,v)];
}
inline int sdis(int u,int v){
	return dep[u]+dep[v]-dep[slca(u,v)]*2;
}
inline int san(int u,int k){
	while(k) u=fa[u][lg[k]],k^=(1<<lg[k]);
	return u;
}
inline int sks(int u,int v,int k){
	int l=slca(u,v);
	if(dep[u]-dep[l]>=k) return san(u,k);
	return san(v,dep[u]+dep[v]-dep[l]*2-k);
}
int ans[N];
struct Node{
	int u,v;
	Node(){}
	Node(int u,int v):u(u),v(v){}
	inline void Add(int u1,int v1){
		if(sdis(u1,v1)>sdis(u,v)) u=u1,v=v1;
	}
	inline Node operator+(Node A){
		Node B=A;
		B.Add(u,v);
		B.Add(u,A.u);
		B.Add(u,A.v);
		B.Add(v,A.u);
		B.Add(v,A.v);
		return B;
	}
} in[N],out[N];
void dfs2(int u,int fa){
	in[u]=Node(u,u);
	for(int i=head[u];i;i=nxt[i]){
		int v=ver[i];
		if(fa==v) continue;
		dfs2(v,u);
		in[u]=in[u]+in[v];
	}
}
vector<int> son;
vector<Node> pre;
void dfs3(int u,int fa){
	//cout<<u<<" and "<<fa<<endl;
	son.clear(),pre.clear();
	for(int i=head[u];i;i=nxt[i]){
		int v=ver[i];
		if(fa!=v) son.push_back(v);
	}
	pre.push_back(Node(u,u));
	for(int i=0;i<son.size();i++){
		pre.push_back(in[son[i]]+pre[i]);
	}
	Node tmp=Node(u,u)+out[u];
	for(int i=son.size()-1;i>=0;i--){
		out[son[i]]=tmp+pre[i];
		tmp=tmp+in[son[i]];
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=ver[i];
		if(fa!=v) dfs3(v,u);
	}
}
int id[N],cc[N];
int dfss(int u,int fa,int p){
	int mx=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=ver[i];
		if(fa!=v&&v!=p) mx=max(mx,1+dfss(v,u,p));
	}
	cc[mx]++;return mx;
}
inline int sol(int u){
	for(int i=0;i<=n;i++) cc[i]=0;
	int s=sks(in[u].u,in[u].v,sdis(in[u].u,in[u].v)/2);
	dfss(s,0,fa[u][0]);
	if(u!=1){
		s=sks(out[u].u,out[u].v,sdis(out[u].u,out[u].v)/2);
		dfss(s,0,u);
	}
	for(int i=n-1;i>=0;i--) cc[i]+=cc[i+1];
	for(int i=0;i<=n;i++) if(cc[i]<=k) return i;
}
inline int f(int x){
	if(x<=10) return 4000;
	if(x<=14) return 600;
	if(x<=17) return 90;
	return 30;
}
void solve(){
	n=read(),k=read();
	for(int i=1;i<=n;i++) head[i]=0;tot=cnt=0;
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		add(u,v);
	}
	dfs(1);
	lg[0]=-1;for(int i=1;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++) mn[dfn[i]][0]=dfn[fa[i][0]];
	for(int j=1;j<=lg[n];j++){
		for(int i=1;i<=n-(1<<j)+1;i++) mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]); 
	}
	for(int j=1;j<=lg[n];j++){
		for(int i=1;i<=n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
	}
	dfs2(1,0);
	//for(int i=1;i<=n;i++,cout<<endl) for(int j=1;j<=n;j++) cout<<sdis(i,j)<<" ";
	//for(int i=1;i<=n;i++) cout<<in[i].u<<","<<in[i].v<<endl;
	out[1]=Node(1,1);dfs3(1,0);
	for(int u=1;u<=n;u++){
		ans[u]=(sdis(in[u].u,in[u].v)+1)/2;
		ans[u]=max(ans[u],(sdis(out[u].u,out[u].v)+1)/2);
	}
	if(k==2){
		int mn=n;
		for(int i=1;i<=n;i++) mn=min(mn,ans[i]);
		put(mn),putchar(10);return;
	}
	for(int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,[](int x,int y){return ans[x]<ans[y];});
	int mn=n;
	for(int i=1;i<=min(n,f(c));i++) mn=min(mn,sol(id[i]));
	put(mn),putchar(10);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	while(T--) solve();
	return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
