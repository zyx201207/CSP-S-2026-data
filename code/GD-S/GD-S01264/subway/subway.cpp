#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=700;
int g[N][N],n,m,c,d,q,w[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f,sizeof(g));
	cin>>c>>n>>m>>d>>q;
	int P=m+10;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int to;cin>>to;
		for(int j=1;j<=to;j++){
			int v;cin>>v;
			cin>>g[P+i][v],g[v][P+i]=g[P+i][v];
		}
	}
	for(int k=1;k<=m+n+10;k++)for(int i=1;i<=m+n+10;i++)for(int j=1;j<=m+n+10;j++)g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	while(q--){
		int u,v;cin>>u>>v;
		cout<<w[u]+w[v]+g[u][v]<<endl;
	}
	return 0;
}
