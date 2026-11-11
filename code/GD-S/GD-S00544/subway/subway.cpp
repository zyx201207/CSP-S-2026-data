#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
#define int long long
int inf=4e18;
int c,n,m,d,q;
int w[M],dis[N][N];
struct dt {
	int ps,t;
};
int ct[M];
dt g[M][21];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		dis[i][i]=0;
		int k; cin>>k;
		for(int j=1;j<=k;j++) {
			int x,t; cin>>x>>t;
			++ct[x];
			g[x][ct[x]]={i,t};
		}
	}
	
	for(int i=1;i<=m;i++) { 
		for(int j=1;j<ct[i];j++) {
			for(int k=j+1;k<=ct[i];k++) {
				int v=g[i][j].t+g[i][k].t;
				int x=g[i][j].ps,y=g[i][k].ps;
				if(v<dis[x][y]) dis[x][y]=dis[y][x]=v;
			}
		}
	}
	// floyd
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			if(i==k) continue;
			for(int j=i+1;j<=n;j++) {
				if(j==k) continue;
				int v=dis[i][k]+dis[k][j];
				if(v<dis[i][j]) dis[i][j]=dis[j][i]=v;
			}
		}
	}
	
	while(q--) {
		int x,y; cin>>x>>y;
		int ans=inf;
		for(int i=1;i<=ct[x];i++) {
			for(int j=1;j<=ct[y];j++) {
				ans=min(ans,dis[g[x][i].ps][g[y][j].ps]+g[x][i].t+g[y][j].t);
			}
		}
		ans=ans+w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
