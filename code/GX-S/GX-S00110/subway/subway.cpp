#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 505,M = 5e5+5;
int test,n,m,d,q,tot=0;ll f[N][N],w[M],t[N][M];
vector<int> in[M];
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&test,&n,&m,&d,&q);
	for(int i=1;i<=m;++i){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;++i){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;++j){
			int u;
			scanf("%d",&u);
			in[u].push_back(i);
			scanf("%lld",&t[i][u]);
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;++i){
		if(in[i].size()>1){
			for(int u:in[i]){
				for(int v:in[i]){
					if(u==v)continue;
					f[u][v] = min(f[u][v],t[u][i]+t[v][i]);
					f[v][u] = f[u][v];
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(k==i||k==j)continue;
				if(i==j){f[i][j] = 0;continue;}
				f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=0;i<q;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		int a,b;ll ans = -1;
		for(int u:in[x]){//meiju road
			for(int v:in[y]){
				//ans = min(ans,f[u][v]);
				if(ans==-1||f[u][v]<ans){
					ans = f[u][v];
					a = u,b=v;
					//printf("\nuv:%d %d\n",u,v);
				}
			}
		}
		printf("%lld\n",ans+w[x]+w[y]+t[a][x]+t[b][y]);
	}
	return 0;
}
