#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,inf=0x3f3f3f3f;
//struct Edge{
//	int to,next;
//}e[N*2];
//int head[N],cnt;
int c,t,n,k,ans=inf,g[15][15];
//void add(int u,int v){
//	e[++cnt]={v,head[u]};
//	head[u]=cnt;
//}
int xz[15];
bool check(){
	int num=k;
	for(int i=1;i<=k;i++){
		for(int j=1;j<i;j++){
			int u=xz[i],v=xz[j];
			if(g[u][v]==1) num--;
		}
	}
	return (num<=2);
}
void dfs(int now,int res){
	if(now>n){
		if(res!=k+1) return ;
		if(!check()) return ;
		int q=0;
		for(int i=1;i<=n;i++){
			int w=inf;
			for(int j=1;j<=k;j++){
				w=min(w,g[i][xz[j]]);
			}
			q=max(q,w);
		}
//		if(q==0) cout<<xz[1]<<" "<<xz[2]<<"\n";
		return ans=min(ans,q),void();
	}
	dfs(now+1,res);
	xz[res]=now,dfs(now+1,res+1),xz[res]=0;
	return ;
}
void work(){
	cin>>n>>k,ans=inf;
//	cnt=0;
//	for(int i=1;i<=n;i++) head[i]=0;
	if(c<=3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) g[i][j]=inf;
			g[i][i]=0;
		}
	}
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		if(c<=3) g[u][v]=g[v][u]=1;
//		add(u,v),add(v,u);
	}
	if(c<=3){
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(g[i][k]==inf||g[k][j]==inf) continue;
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
		dfs(1,0);
		return cout<<ans<<"\n",void();
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>t;	
	while(t--) work();
	return 0;
}
