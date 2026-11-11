#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=550,M=5e5+50;
int c,n,m,d,q; 
int w[M];
vector<pii>p[M];
ll f[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1,k;i<=n;i++){
		f[i][i]=0;
		scanf("%d",&k);
		for(int j=1,v,w;j<=k;j++){
			scanf("%d%d",&v,&w);
			p[v].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++){
		int len=p[i].size();
		for(int j=0;j<len-1;j++)
			for(int k=j+1;k<len;k++){
				int u=p[i][j].first,v=p[i][k].first;
				ll w=1ll*p[i][j].second+1ll*p[i][k].second;
				f[u][v]=min(f[u][v],w);
				f[v][u]=min(f[v][u],w);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1,u,v;i<=q;i++){
		scanf("%d%d",&u,&v);
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(auto a:p[u])
			for(auto b:p[v])
				ans=min(ans,1ll*a.second+1ll*b.second+f[a.first][b.first]);
		printf("%lld\n",ans+1ll*w[u]+1ll*w[v]);
	}
	return 0;
} 
