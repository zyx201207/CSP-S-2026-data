#include<bits/stdc++.h>
using namespace std;
#define int long long
const int V=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,G[505][505],len[520005],inval[520005];
struct node {int v,w;}s[520005][25];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>inval[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)G[i][j]=V;
	for(int i=1,k,v,w;i<=n;i++) {
		cin>>k,G[i][i]=0;
		while(k--)cin>>v>>w,s[v][++len[v]]={i,w};
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=len[i];j++)
			for(int k=1;k<j;k++) {
				int u=s[i][j].v,v=s[i][k].v,w=s[i][j].w+s[i][k].w;
				G[u][v]=min(G[u][v],w),G[v][u]=min(G[v][u],w);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
	while(q--) {
		int x,y,ans=V;
		cin>>x>>y;
		for(int j=1;j<=len[x];j++)
			for(int k=1;k<=len[y];k++) {
				int u=s[x][j].v,v=s[y][k].v,w=s[x][j].w+s[y][k].w;
				ans=min(ans,G[u][v]+w);
			}
		cout<<inval[x]+inval[y]+ans<<endl;
	}
	return 0;
} 
