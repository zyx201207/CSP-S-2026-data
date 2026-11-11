#include <bits/stdc++.h>
using namespace std;
#define gc getchar()
#define pb push_back
typedef long long ll;
const int N=5e5+5,M=505;
ll rd() {
	ll x=0,f=1; char c=gc;
	for(;c<'0'||c>'9';c=gc)if(c=='-')f=-1;
	for(;c>='0'&&c<='9';x=x*10+c-'0',c=gc);
	return x*f;
}
int c,n,m,d,q;
ll w[N],deg[N],to[N][25],val[N][25],f[M][M];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd(); n=rd(); m=rd(); d=rd(); q=rd();
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++) w[i]=rd();
	for(int i=1;i<=n;i++) {
		int k=rd();
		for(int j=1;j<=k;j++) {
			int a=rd(); ll t=rd();
			deg[a]++; to[a][deg[a]]=i; val[a][deg[a]]=t;
		}
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=deg[i];j++) for(int k=j;k<=deg[i];k++) {
			int x=to[i][j],y=to[i][k];
			f[x][y]=min(f[x][y],val[i][j]+val[i][k]);
			f[y][x]=f[x][y];
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
	for(int x,y;q;q--) {
		x=rd(); y=rd();
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=deg[x];i++) for(int j=1;j<=deg[y];j++) {
			int u=to[x][i],v=to[y][j];
			ans=min(ans,w[x]+val[x][i]+f[u][v]+val[y][j]+w[y]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
