#include <bits/stdc++.h> 
using namespace std;
using ll=long long;
void chkmax(int &x,int y){ if(x<y) x=y; }
void chkmin(int &x,int y){ if(x>y) x=y; }
const int N=2e6+5;
int n,k,far,st[N],vis[N],top,dep[N],Dep[N],Far,F[N];
vector<int>e[N];
void dfs(int u,int fa){
	for(int v:e[u]) if(v!=fa&&!vis[v]){
		dep[v]=dep[u]+1,dfs(v,u);
	}
	if(dep[u]>dep[far]) far=u;
}
bool DFS(int u,int fa,int ed){
	st[++top]=u;
	if(u==ed) return true;
	for(int v:e[u]) if(v!=fa)
		if(DFS(v,u,ed)) return true;
	return --top,false;
}
void Dfs(int u,int fa){
	for(int v:e[u]) if(v^fa){
		if(vis[v])continue;
		Dep[v]=Dep[u]+1,Dfs(v,u);
	}
	if(Dep[u]>Dep[Far]) Far=u;
}
void Q(int u){
	if(vis[u]==-1) vis[u]=1;
	else return ;
	for(int v:e[u]) Q(v);
}
void Mutsumi(){
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		e[u].emplace_back(v);
		e[v].emplace_back(u); 
	}
	for(int i=1;i<=n;i++)vis[i]=0; 
	if(k==1){
		dfs(dep[1]=far=1,0);
		int rt=far;dep[far]=1;
		dfs(far,0);
		printf("%d\n",dep[far]+1>>1);
	}else if(n<=10){
		int res=n+1;
		for(int s=0;s<(1<<n);s++){
			int c=0;
			for(int j=0;j<n;j++)
				if(s>>j&1) ++c;
			if(c!=k) continue;
			for(int j=0;j<n;j++)vis[j+1]=0;
			for(int j=0;j<n;j++)
				if(s>>j&1)vis[j+1]=-1;
			int G=0;
			for(int j=0;j<n;j++)
				if(vis[j+1]==-1) Q(j+1),++G;
			if(G>2) continue;
			int mxd=0;
			for(int i=1;i<=n;i++) F[i]=n+1;
			for(int i=1;i<=n;i++) if(!vis[i])
				for(int j=1;j<=n;j++)
					if(vis[j]){
						top=0,DFS(i,0,j);
						chkmin(F[i],top-1);
					}
			for(int i=1;i<=n;i++) if(!vis[i]) chkmax(mxd,F[i]);
			chkmin(res,mxd);
		}
		printf("%d\n",res);
	}else if(k==2){
		int res=n+1;
		for(int i=1;i<=n;i++){
			vector<int>w;vis[i]=1;
			for(int u:e[i]){
				dep[u]=0,dfs(far=u,0);
				int rt=far;dep[far]=0;
				dfs(far,0);
				w.emplace_back(dep[far]);
			}
			sort(w.begin(),w.end());
			int mxd=w.back()+1>>1;
			for(int y:w) chkmax(mxd,y);
			chkmin(res,mxd);
			vis[i]=0;
		}
		printf("%d\n",res);
	}
	for(int i=1;i<=n;i++) e[i].clear();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T=1; scanf("%d%d",&C,&T);
	while(T--) Mutsumi();
	return 0;
}
