#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q,w[M],dis[N][N],cnt[M];
struct node {int id,w;}e[M][22];
signed main() {
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
//	freopen("subway7.in","r",stdin),freopen("data.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1,k;i<=n;i++) {
		cin>>k;
		for(int j=1,x,y;j<=k;j++) cin>>x>>y,e[x][++cnt[x]]=(node){i,y};
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=cnt[i];j++) 
		for(int k=1;k<=cnt[i];k++) {
			int id1=e[i][j].id,id2=e[i][k].id,w1=e[i][j].w,w2=e[i][k].w;
			dis[id1][id2]=min(dis[id1][id2],w1+w2);
			dis[id2][id1]=min(dis[id2][id1],w1+w2);
		} 
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--) {
		int x,y,ans=inf;
		cin>>x>>y;
		for(int i=1;i<=cnt[x];i++) 
		for(int j=1;j<=cnt[y];j++) {
			int id1=e[x][i].id,id2=e[y][j].id,w1=e[x][i].w,w2=e[y][j].w;
			ans=min(ans,dis[id1][id2]+w1+w2+w[x]+w[y]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
