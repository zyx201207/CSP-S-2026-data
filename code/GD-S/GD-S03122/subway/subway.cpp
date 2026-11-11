#include <bits/stdc++.h> 
using namespace std;
using ll=long long;
void chkmin(ll &x,ll y){ if(x>y) x=y; }
const int N=505,M=5e5+5,D=25;
const ll inf=1e18;
int C,n,m,d,q,a[M],e[M][D],w[M][D],sz[M]; ll f[N][N];
void Mutsumi(){
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		int k,x,y; scanf("%d",&k);
		while(k--) scanf("%d%d",&x,&y),++sz[x],e[x][sz[x]]=i,w[x][sz[x]]=y;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i^j) f[i][j]=inf;
	for(int i=1;i<=m;i++)
		for(int j=1;j<sz[i];j++)
			for(int k=j+1;k<=sz[i];k++){
				chkmin(f[e[i][j]][e[i][k]],w[i][j]+w[i][k]);
				chkmin(f[e[i][k]][e[i][j]],w[i][j]+w[i][k]);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				chkmin(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int u,v; scanf("%d%d",&u,&v);
		ll res=inf;
		for(int i=1;i<=sz[u];i++)
			for(int j=1;j<=sz[v];j++)
				chkmin(res,w[u][i]+w[v][j]+f[e[u][i]][e[v][j]]);
		printf("%lld\n",res+a[u]+a[v]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
	while(T--) Mutsumi();
	return 0;
}
