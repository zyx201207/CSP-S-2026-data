#include <bits/stdc++.h>
using namespace std;
const long long N=510,M=5e5+10,D=30,INF=1e18;
long long c,n,m,d,q;
long long w[M];
struct Edge{
	long long v,w;
};
vector<Edge> gt[M];
long long g[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q); 
	for(long long i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(long long i=1;i<=n;i++){
		long long k;
		scanf("%d",&k);
		for(long long j=1;j<=k;j++){
			long long a,t;
			scanf("%d%d",&a,&t);
			gt[a].push_back({i,t});
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			g[i][j]=INF;
			if(i==j){
				g[i][j]=0;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		int l=gt[i].size();
		for(int x=0;x<l;x++){
			for(int y=x+1;y<l;y++){
				Edge e1=gt[i][x],e2=gt[i][y];
				g[e1.v][e2.v]=g[e2.v][e1.v]=min(g[e1.v][e2.v],e1.w+e2.w);
			}
		}
	}
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	for(long long i=1;i<=q;i++){
		long long x,y;
		scanf("%d%d",&x,&y);
		long long ans=INF;
		for(auto e1:gt[x]){
			for(auto e2:gt[y]){
				ans=min(ans,e1.w+e2.w+g[e1.v][e2.v]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
