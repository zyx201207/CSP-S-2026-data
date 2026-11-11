#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans=2e9;
int w[500005],k[505],t[505][500005],ar[505][20005],tr;
bool a[505][500005],vis[505][20005];
vector<int>g[500005];
int x,y;
int tmp;
void find(int u,int b,int f){
	for(int i=0;i<g[u].size();i++){
		for(int j=1;j<=k[g[u][i]];j++){
			int v=ar[g[u][i]][j];
			if(v==f){
				ans=min(ans,b+t[g[u][i]][u]+t[g[u][i]][f]+w[f]);
				return;
			}
			if(vis[g[u][i]][j]==1||v==u) continue;
			vis[g[u][i]][j]=1;
			find(v,b+t[g[u][i]][u]+t[g[u][i]][v],f);
		}
		
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",w+i);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d %d",&ar[i][j],&tr);
			a[i][ar[i][j]]=1;
			t[i][ar[i][j]]=tr;
			g[ar[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d",&x,&y);
		ans=2e9;
		
		for(int i=1;i<=n;i++){
			if(a[i][x]&&a[i][y]){
				ans=min(ans,w[x]+w[y]+t[i][x]+t[i][y]);
			}
		}
		if(ans==2e9){
			memset(vis,0,sizeof(vis));
			find(x,w[x],y);
		}
		printf("%d\n",ans);
	}
}
