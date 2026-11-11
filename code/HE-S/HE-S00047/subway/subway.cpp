#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=505,M=5e5+5;
int w[M];
vector<pair<int,int>> a[M];
ll f[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,Q;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int u,t;
			scanf("%d %d",&u,&t);
			a[u].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto p1:a[i]){
			for(auto p2:a[i]){
				int u=p1.first,v=p2.first;
				if(u==v) continue;
				ll w=p1.second+p2.second;
				f[u][v]=min(f[u][v],w);
				f[v][u]=min(f[v][u],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(Q--){
		int x,y;
		scanf("%d %d",&x,&y);
		ll ans=1e18;
		for(auto p1:a[x]){
			for(auto p2:a[y]){
				int u=p1.first,v=p2.first;
				ans=min(ans,f[u][v]+w[x]+w[y]+p1.second+p2.second);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

