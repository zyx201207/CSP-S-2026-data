#include <bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],k[N];
long long ans,g[N][N];
struct St{
	int to,w;
};
vector<St> v[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) g[i][j]=0;
			else g[i][j]=2e18;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int a,t;
			scanf("%d%d",&a,&t);
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=j+1;k<v[i].size();k++){
				g[v[i][k].to][v[i][j].to]=g[v[i][j].to][v[i][k].to]=min(g[v[i][j].to][v[i][k].to],1ll*
				v[i][j].w+v[i][k].w);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue ;
			for(int k=1;k<=n;k++){
				if(i!=k&&j!=k){
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
	}
	
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ans=1e18;
		for(St i:v[x]){
			for(St j:v[y]){
				ans=min(ans,i.w+j.w+g[i.to][j.to]);
			}
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
} 
