#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
priority_queue<pair<long long,int>> qu;
int c,n,m,d,q,wout[N],k[505],a[N],t[N],cnt[N],beg[N],tmp,x,y;//cnt[] is the cnt of line[i][],beg is the begining of a[i] and t[i] 
short line[N][20];
long long dis[N];
bool vis[N];
void dijkstra(int x){
	for(int i=1;i<=m;i++) dis[i]=1e18;
	memset(vis,0,sizeof vis);
	dis[x]=0;
	qu.push({0,x});
	while(!qu.empty()){
		int u=qu.top().second;
		qu.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=1;i<=cnt[u];i++){
			int l=line[u][i];
			for(int j=1;j<=k[l];j++){
				if(a[beg[l]+j]==u){
					tmp=j;
				}
			}
			for(int j=1;j<=k[l];j++){
				if(j==tmp) continue;
				int v=a[beg[l]+j],w=t[beg[l]+tmp]+t[beg[l]+j];
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					qu.push({-dis[v],v});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&wout[i]);
	for(int i=1;i<=n;i++){
		beg[i]=beg[i-1]+k[i-1];
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[beg[i]+j],&t[beg[i]+j]);
			line[a[beg[i]+j]][++cnt[a[beg[i]+j]]]=i;
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		dijkstra(x);
		printf("%lld",dis[y]+wout[x]+wout[y]);
	}
	return 0;
}
