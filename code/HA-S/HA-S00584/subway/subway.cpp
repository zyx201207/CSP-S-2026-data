#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
const int N=550,M=5e5+100;
const ll inf=1e18;
ll dis[N][N],val[M]; 
int id[M][22],w[M][22],cnt[M];
int read() {int x;cin>>x;return x;}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++) {
		val[i]=read();
	}
	for(int i=1;i<=n;i++) {
		int k=read();
		for(int j=1;j<=k;j++) {
			int x=read();int val=read();
			++cnt[x];
			id[x][cnt[x]]=i;
			w[x][cnt[x]]=val;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=cnt[i];++j) {
			for(int k=j+1;k<=cnt[i];++k) {
				dis[id[i][j]][id[i][k]]=dis[id[i][k]][id[i][j]]=min(dis[id[i][k]][id[i][j]],1ll*(w[i][j]+w[i][k]));
			}
		}
	}
	for(int i=1;i<=n;i++) {
		dis[i][i]=0;
	}
	for(int k=1;k<=n;++k) {
		for(int j=1;j<=n;++j) {
			for(int i=j+1;i<=n;++i) {
				dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;++i) {
		int u,v;
		u=read();v=read();
		ll ans=inf;
		for(int j=1;j<=cnt[u];++j) {
			for(int k=1;k<=cnt[v];++k) {
				ans=min(ans,dis[id[u][j]][id[v][k]]+w[u][j]+w[v][k]);
			}
		}
		cout<<ans+val[u]+val[v]<<"\n";
	}
	return 0;
}
/*

 
*/
