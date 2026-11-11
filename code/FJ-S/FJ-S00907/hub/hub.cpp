#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	char c;
	int x=0,f=1;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int MAXN=5e6+5;
int test,t,n,m;
int head[MAXN],cnt;
struct line{
	int to,nxt;
}a[MAXN];
void add(int u,int v){
	a[++cnt].to=v;
	a[cnt].nxt=head[u];
	head[u]=cnt;
}
int dep[MAXN],fu[MAXN][25];
void dfs(int k,int f){
	dep[k]=dep[f]+1;
	fu[k][0]=f;
	for(int i=1;i<=20;i++){
		fu[k][i]=fu[fu[k][i-1]][i-1];
	}
	for(int i=head[k];i;i=a[i].nxt){
		int v=a[i].to;
		if(v==f) continue;
		dfs(v,k);
	}
}
int vis[MAXN],sonmax[MAXN],siz;
vector<int> p;
void change(int k,int f,int x){
	sonmax[k]=-1;
	int cmax=-1;
	bool flag=0;
	for(int i=head[k];i;i=a[i].nxt){
		int v=a[i].to;
		if(v==f) continue;
		change(v,k,x);
		if(vis[v]==1){
			flag=1;
			continue;
		}
		if(sonmax[v]>sonmax[k]){
			cmax=sonmax[k];
			sonmax[k]=sonmax[v];
		}
		else if(sonmax[v]>cmax){
			cmax=sonmax[v];
		}
	}
	sonmax[k]++;
	if(sonmax[k]==0) return;
	if(flag&&sonmax[k]+1<x) return;
	if(!flag&&cmax+sonmax[k]+1<x) return;
	vis[k]=1;
	p.push_back(k);	
	siz++;
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]){
		int lg=log2(dep[x]-dep[y]);
		x=fu[x][lg];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(fu[x][i]!=fu[y][i]){
			x=fu[x][i];
			y=fu[y][i];
		}
	}
	return fu[x][0];
}
struct edge{
	int st,fn,d;
}b[MAXN];
int ct;
void edge_add(int u,int v,int d){
	b[++ct].st=u;
	b[ct].fn=v;
	b[ct].d=d;
}
bool cmp(edge x,edge y){
	return x.d<y.d;
}
int fa[MAXN];
int find(int k){
	if(fa[k]!=k) fa[k]=find(fa[k]);
	return fa[k];
}
bool check(int x){
	if(x==0){
		if(n<=m) return true;
		return false;
	}
	p.clear();
	ct=siz=0;
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	change(1,0,x);
	if(siz>m) return false;
	for(int i=0;i<siz;i++){
		for(int j=i+1;j<siz;j++){
			int u=p[i],v=p[j];
			int d=dep[u]+dep[v]-2*dep[lca(u,v)]-1;
			edge_add(i+1,j+1,d);
			edge_add(j+1,i+1,d);
		}
	}
	for(int i=1;i<=siz;i++){
		fa[i]=i;
	}
	sort(b+1,b+1+ct,cmp);
	int mx=m-siz,res=0;
	for(int i=1;i<=ct;i++){
		int u=b[i].st,v=b[i].fn;
		int uf=find(u),vf=find(v);
		if(uf==vf){
			continue;
		}
		if(mx<b[i].d) break;
		mx-=b[i].d;
		fa[uf]=vf;
		res++;
		if(res==siz-1) break;
	}
	int dif=0;
	for(int i=1;i<=siz;i++){
		if(fa[i]==i) dif++;
	}
	if(dif<=2) return true;
	return false;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	test=read();t=read();
	while(t--){
		n=read();m=read();
		cnt=0;
		for(int i=1;i<=n;i++){
			head[i]=0;
		}
		for(int i=1;i<n;i++){
			int x,y;
			x=read();y=read();
			add(x,y);
			add(y,x);
		}
		dfs(1,0);
		int l=0,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		cout<<l<<endl;
	}
	return 0;
}
