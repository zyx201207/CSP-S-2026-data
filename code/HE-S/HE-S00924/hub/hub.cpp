#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+3,INF=1e9+3;

int c,t,n,k;
int first[maxn],nxt[maxn<<1],to[maxn<<1],tot;
void add(int x,int y){
	nxt[++tot]=first[x];first[x]=tot;to[tot]=y;
}

int dep[maxn],f[maxn][21];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for(int i=1;i<=20;i++){
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(int i=first[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa)continue;
		f[v][0]=u;
		dfs(v,u);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[f[x][i]]>dep[y]){
			x=f[x][i];
		}
	}
	if(x==y)return x;
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i],y=f[y][i];
		}
	}
	return f[x][0];
} 
int dist(int x,int y){
	int fa=lca(x,y);
	return dep[x]+dep[y]-2*dep[fa];
}

void initial(){
	memset(first,0,sizeof(first));
	memset(nxt,0,sizeof(nxt));
	tot=0;
	memset(dep,0,sizeof(dep));
	for(int i=0;i<maxn;i++){
		for(int j=0;j<21;j++)f[i][j]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==7||c==11||c==12){
		while(t--){
			initial();
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v;cin>>u>>v;
				add(u,v);add(v,u);
			}
			dfs(1,0);
			int ans=INF;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int res=0;
					for(int d=1;d<=n;d++){
						res=max(res,min(dist(d,i),dist(d,j)));
					}
					ans=min(ans,res);
				}
			}
			cout<<ans<<endl;	
		}	
	}
	return 0;
}
