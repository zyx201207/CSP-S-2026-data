#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int C,n,m,d,q,x,y;//地铁线路数,地铁站数,每个站最多被几路过,出行计划数,起点和终点 
int w[500010],k[510],a[510][50010],b[510][50010],vis[50010],vl[510],ans=INT_MAX;//地铁口走到站厅的时间,线经过的站数,aij:i线上有j站,bij在i线上j站走到展厅的时间 
void dfs(int u,int l,int fa){//i站，在l线上，由fa而来 
	if(u==y){
		ans=min(ans,vis[y]+w[y]+b[l][y]);
		return;
	}
	for(int i=1;i<=m;i++){
		if(i!=u && i!=fa && (vis[i]>vis[u]) && a[l][i]){
			vis[i]=vis[u];
			dfs(i,l,u);
		}
	} 
	//换乘
	for(int i=1;i<=n;i++){
		if(a[i][u] && i!=l && !vl[i]){
			vl[i]=1;
			vis[u]+=b[l][u]+b[i][u];
			dfs(u,i,fa);
			vl[i]=0;
		}
	}
	
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
	//cin>>C>>n>>m>>d>>q;
	memset(a,0,sizeof(a));
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);//cin>>w[i];
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d",&x);
			scanf("%d",&b[i][x]);
			a[i][x]=1;
		}
	}
	while(q--){
		memset(vis,0x3f3f3f,sizeof(vis));
		scanf("%d%d",&x,&y);
		for(int i=1;i<=n;i++){
			memset(vl,0,sizeof(vl));
			if(a[i][x]){
				vl[i]=1;
				vis[x]=w[x]+b[i][x];
				dfs(x,i,0); 
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
