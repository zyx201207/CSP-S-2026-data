#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=5e5+10,M=5e2+10;
const int INF=1e18;
int Id;
int n,m,De,c;
int a[N];
struct Node { int x,w; } ;
vector<Node>H[N];
int D[M][M];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&Id,&n,&m,&De,&c);
	for(int i=1;i<=m;i++) scanf("%lld",&a[i]);
	int len,x,k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&len);
		for(int j=1;j<=len;j++){
			scanf("%lld%lld",&x,&k);
			H[x].pb({i,k});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			D[i][j]=INF; 
		}
	}
	for(int i=1;i<=m;i++){
		int len=H[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				int u=H[i][j].x,v=H[i][k].x,w=H[i][j].w+H[i][k].w;
				D[u][v]=min(D[u][v],w); 
				D[v][u]=min(D[v][u],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) D[i][j]=min(D[i][j],D[i][k]+D[k][j]); 
		}
	}
	int u,v;
	for(int i=1;i<=c;i++){
		scanf("%lld%lld",&u,&v);
		if(u==v) { printf("0\n"); continue; }
		int ans=INF;
		for(auto o1 : H[u]){
			for(auto o2 : H[v]) ans=min(ans,D[o1.x][o2.x]+o1.w+o2.w);
		}
		printf("%lld\n",ans+a[u]+a[v]);
	}
	return 0;
}
