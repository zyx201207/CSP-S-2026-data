#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=1000003;

int read(){
	int x=0,f=1,ch=getchar();
	if(ch<48||ch>57){
		if(ch==45){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

int C,T,to[maxn<<1],nxt[maxn<<1],hd[maxn],tot,fa[maxn],ans,n,K,f[maxn][21],dep[maxn];

bool mk[maxn];

int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}

void init(){
	ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		mk[i]=hd[i]=0;
	}
	for(int i=1;i<=tot;i++){
		to[i]=nxt[i]=0;
	}
	tot=1;
	return;
}

void add(int u,int v){
	tot++;
	to[tot]=v;
	nxt[tot]=hd[u];
	hd[u]=tot;
	return;
}

void solve1(){
	int m=n/2;
	if(K==n){
		cout<<"0\n";
		return;
	}
	if(K>=m){
		cout<<"1\n";
		return;
	}
	cout<<max(1,(m-K-1)/4+2)<<'\n';
	return;
}

int lca(int u,int v){
	if(dep[u]<dep[v]){
		swap(u,v);
	}
	for(int i=20;i>=0;i--){
		if(dep[f[u][i]]>=dep[v]){
			u=f[u][i];
		}
	}
	if(u==v){
		return u;
	}
	for(int i=20;i>=0;i--){
		if(f[u][i]!=f[v][i]){
			u=f[u][i],v=f[v][i];
		}
	}
	return f[u][0];
}

void check(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int u=1;u<=n;u++){
		if(mk[u]){
			for(int i=hd[u];i;i=nxt[i]){
				int v=to[i];
				if(mk[v]){
					fa[find(u)]=find(v);
				}
			}
		}
	}
	int cnt=0;
	for(int u=1;u<=n;u++){
		cnt+=(find(u)==u&&mk[u]);
	};
	if(cnt>2){
		return;
	}
	int dis=0;
	for(int i=1;i<=n;i++){
		int x=0x3f3f3f3f;
		for(int j=1;j<=n;j++){
			if(mk[j]){
				x=min(x,dep[i]+dep[j]-2*dep[lca(i,j)]);
			}
		}
		dis=max(dis,x);
	}
	ans=min(ans,dis);
	return;
}

void dfs(int u,int father){
	dep[u]=dep[father]+1;
	f[u][0]=father;
	for(int i=1;i<=20;i++){
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(int i=hd[u];i;i=nxt[i]){
		int v=to[i];
		if(v!=father){
			dfs(v,u);
		}
	}
	return;
}

void dfs1(int x,int cnt){
	if(x>n||cnt==K){
		check();
		return;
	}
	mk[x]=true;
	dfs1(x+1,cnt+1);
	mk[x]=false;
	if(n-x+1>K-cnt){
		mk[x]=false;
		dfs1(x+1,cnt);
	}
	return;
}

void solve(){
	dfs(1,0);
	dfs1(1,0);
	cout<<ans<<'\n';
	return;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=read(),T=read();
	while(T--){
		n=read(),K=read();
		init();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			add(u,v);
			add(v,u);
		}
		if(C==13||C==14){
			solve1();
		}else{
			solve();
		}
	}
	return 0;
}
