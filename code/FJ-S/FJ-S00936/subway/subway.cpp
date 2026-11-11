#include<bits/stdc++.h>
#define N 503
#define M 500003
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m,d,q,w[M],siz[M];
vector<int> t[M],id[M];
ll f[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	scanf("%*d%d%d%d%d",&n,&m,&d,&q);
	for(int i=1;i<=m;++i) scanf("%d",&w[i]);
	for(int i=1;i<=n;++i){
		int k; scanf("%d",&k); f[i][i]=0;
		for(int j=1;j<=k;++j){
			int x,y; scanf("%d%d",&x,&y);
			t[x].push_back(y); id[x].push_back(i);
		}
	}
	for(int i=1;i<=m;++i) siz[i]=t[i].size();
	for(int i=1;i<=m;++i){
		for(int j=0;j<siz[i];++j){
			for(int k=j+1;k<siz[i];++k)
				f[id[i][j]][id[i][k]]=f[id[i][k]][id[i][j]]=min(f[id[i][j]][id[i][k]],(ll)t[i][j]+t[i][k]);
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
	while(q--){
		int x,y; scanf("%d%d",&x,&y);
		ll ans=INF;
		for(int i=0;i<siz[x];++i){
			for(int j=0;j<siz[y];++j)
				ans=min(ans,(ll)w[x]+w[y]+t[x][i]+t[y][j]+f[id[x][i]][id[y][j]]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
