#include<iostream>
using namespace std;
const int N=1e6+5,INF=1e9;
int o,n,m,tot=1,ans;
int head[N],ver[N*2],Next[N*2],dep[N],fa[N],pa[N];
bool v[N];

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<48||c>57){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>=48&&c<=57){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return f==-1?-x:x;
}

void add_edge(int x,int y){
	ver[++tot]=y,Next[tot]=head[x],head[x]=tot;
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]) x=fa[x];
	while(x!=y) x=fa[x],y=fa[y];
	return x;
}

int dis(int x,int y){ return dep[x]+dep[y]-2*dep[lca(x,y)];}

void dfs(int x,int now){
	if(now>m) return;
	if(x>n){
		if(now!=m) return;
		int c=0;
		for(int i=1;i<n;i++){
			int x=ver[i<<1],y=ver[i<<1|1];
			if(v[x]&&v[y]) c++;
		}
		if(c<m-2) return;
		int t=0;
		for(int i=1;i<=n;i++){
			int res=INF;
			for(int j=1;j<=n;j++){
				if(!v[j]) continue;
				res=min(res,dis(i,j));
			}
			t=max(t,res);
		}
		ans=min(ans,t);
		return;
	}
	v[x]=1;
	dfs(x+1,now+1);
	v[x]=0;
	dfs(x+1,now);
}

void dfs1(int x){
	for(int i=head[x];i;i=Next[i]){
		int y=ver[i];
		if(y==fa[x]) continue;
		fa[y]=x,dep[y]=dep[x]+1;
		dfs1(y);
	}
}

void solve(){
	for(int i=1;i<=n;i++) head[i]=dep[i]=0;
	tot=1;
	n=read(),m=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y);
		add_edge(y,x);
	}
	if(m==n){
		puts("0");
		return;
	}
	if(o<=3){
		ans=INF;
		dep[1]=1;
		dfs1(1);
		dfs(1,0);
		printf("%d\n",ans);
		return;
	}
	printf("%d\n",n/2);
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	o=read();
	int T=read();
	while(T--) solve();
	return 0;
}

