#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;

const int N=2e6+10;

int cas,T,n,k,fin;
int h[N],nxt[N],to[N],idx;
int dep[N/2],f[N/2][22],ch[N];

void add(int u,int v){
	to[idx]=v;
	nxt[idx]=h[u];
	h[u]=idx++;
}

vector <int> vec;

int fa[N];

int find(int x){
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	return fa[x];
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	int delta=dep[x]-dep[y];
	rep(i,0,20) if(delta>>i&1) x=f[x][i];
	if(x==y) return x;
	per(i,20,0){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}

void chk(){
	rep(i,0,n-1) fa[i]=i;
	rep(i,0,n-1){
		for(int j=h[i];j!=-1;j=nxt[j]){
			int fu=find(i),fv=find(to[j]);
			if(ch[i]&&ch[to[j]]){
				if(fu==fv) continue;
				fa[fu]=fv;	
			}
		}
	}
	set <int> s;
	s.clear();
	rep(i,0,n-1) if(ch[i]) s.insert(find(i));
	if(s.size()>2) return ;
	int ans=0;
	rep(i,0,n-1){
		if(ch[i]) continue;
		int res=n-1;
		rep(j,0,n-1) if(ch[j]) res=min(res,dis(i,j));
		ans=max(ans,res);
	}
	fin=min(fin,ans);
	return;
}

void dfs(int u,int ft){
	dep[u]=dep[ft]+1;
	f[u][0]=ft;
	rep(i,1,20) f[u][i]=f[f[u][i-1]][i-1];
	for(int j=h[u];j!=-1;j=nxt[j]){
		int v=to[j];
		if(v==ft) continue;
		dfs(v,u);
	}
}

int lft;

void dfs2(int u,int ft){
	if(u==lft) dep[u]=0;
	else dep[u]=dep[ft]+1;
	for(int j=h[u];j!=-1;j=nxt[j]){
		int v=to[j];
		if(v==ft) continue;
		dfs2(v,u);
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&cas,&T);
	while(T--){
		scanf("%d%d",&n,&k);
		fin=n-1; 
		rep(i,0,n-1) h[i]=-1,nxt[i]=nxt[i+n]=to[i]=to[i+n]=0;
		rep(i,1,n-1){
			int u,v;
			scanf("%d%d",&u,&v);u--,v--;
			add(u,v);add(v,u);
		}
		dfs(0,0);
		if(cas<=3){
			rep(msk,0,(1<<n)-1){
				if(__builtin_popcount(msk)!=k) continue;
				rep(i,0,n-1) if(msk>>i&1) ch[i]=1;
				chk();
				rep(i,0,n-1) ch[i]=0;
			}
		}
		else if(k==1){
			dfs(0,0);
			lft=0;
			rep(i,0,n-1) if(dep[i]>dep[lft]) lft=i;
			rep(i,0,n-1) dep[i]=0;
			dfs2(lft,-1); 
			int res=0;
			rep(i,0,n-1) res=max(res,(dep[i]+1)/2);
			fin=res;
		}
		else if(k==2){
			rep(i,0,n-1){
				rep(j,i+1,n-1){
					ch[i]=1,ch[j]=1;
					chk();
					ch[i]=0,ch[j]=0;
				}
			}
		}
		rep(i,0,n-1){
			dep[i]=0;
			rep(j,0,20) f[i][j]=0;
		}
		printf("%d\n",fin);
	}
	return 0; 
} 
