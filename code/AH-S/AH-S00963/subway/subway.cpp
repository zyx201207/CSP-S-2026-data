#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005,CN=1e6+5,M=1e5+5;
int a[N][N];
bool f[N];
ll w[N],t[N][N],g[N][N],dist[N][N];
void dijkstra(int st,int n){
	memset(f,0,sizeof(f));
	dist[st][st]=0;
	for(int i=1;i<n;i++){
		int t=-1;
		for(int j=1;j<=n;j++){
			if(!f[j]&&(t==-1||dist[st][t]>dist[st][j])) t=j;
		}
		f[t]=1;
		for(int j=1;j<=n;j++){
			if(!f[j]&&dist[st][t]+g[t][j]<dist[st][j]){
				dist[st][j]=dist[st][t]+g[t][j];
			}
		}
	}
}
//void floyd(int n){
//	for(int i=1;i<=n;i++) dist[i][i]=0;
//	for(int k=1;k<=n;k++){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
////				cout<<dist[i][j]<<" "
//				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
//			}
//		}
//	}	
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dist,0x3f,sizeof(dist));
	memset(g,0x3f,sizeof(g));
	int c,n,m,d,q,s,x,y;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&s);
		for(int j=1;j<=s;j++){
			scanf("%d%lld",&a[i][j],&t[i][j]);
			for(int l=j-1;l>=1;l--){
				x=a[i][j],y=a[i][l];
				g[x][y]=min(g[x][y],t[i][j]+t[i][l]);
				g[y][x]=min(g[y][x],t[i][j]+t[i][l]);
//				dist[x][y]=g[x][y],dist[y][x]=g[y][x];
			}
		}
	} 
	for(int i=1;i<=m;i++) dijkstra(i,m);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
//			cout<<dist[i][j]<<" ";
			dist[i][j]+=(w[i]+w[j]);
		}
//		cout<<"\n";
	}
	while(q--){
		scanf("%d%d",&x,&y);
		printf("%lld\n",dist[x][y]);
	}
	return 0;
}
