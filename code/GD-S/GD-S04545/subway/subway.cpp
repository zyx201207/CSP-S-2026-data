#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=505;
const int M=5e5+5;
int c,n,m,d,q,x,u,v,w[M],k[N];
long long ans,f[N][N];
vector<pair<int,int> > gm[M],gn[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&x,&v);
			gm[x].push_back(make_pair(i,v));
			gn[i].push_back(make_pair(x,v));
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=1e18;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=n;i++){
		for(auto j:gn[i]){
			for(auto p:gm[j.fi]){
				f[i][p.fi]=min(f[i][p.fi],(long long)j.se+(long long)p.se);
			}
		}
	}
	for(int p=1;p<=n;p++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][p]+f[p][j]);
	while(q--){
		scanf("%d%d",&u,&v);
		ans=1e18;
		for(auto i:gm[u]) for(auto j:gm[v]) ans=min(ans,f[i.fi][j.fi]+i.se+j.se);
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
