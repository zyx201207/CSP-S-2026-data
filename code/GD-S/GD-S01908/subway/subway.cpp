#include<bits/stdc++.h>
#define endl '\n'
#define INF 2e18
#define int long long
#define fi first
#define se second
#define pb push_back
#define mem(x,v) memset(x,v,sizeof x)
using namespace std;
const int N = 505;
const int M = 5e5+5;
const int V = 2*M+N;

int c,n,m,d,q;
int w[M],f[N][N];
vector <pair<int,int> > g[M];
//AC 15:44
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q,mem(f,0x3f);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k,a,t;i<=n;i++){
		f[i][i]=0;
		cin>>k;while(k--){cin>>a>>t;
			g[a].pb({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int uid=0;uid<g[i].size();uid++){
			for(int vid=0;vid<uid;vid++){
				int u=g[i][uid].fi,v=g[i][vid].fi,w=g[i][uid].se+g[i][vid].se;
				f[u][v]=min(f[u][v],w),f[v][u]=min(f[v][u],w);
			}
		}
	}
//	cout<<123123112<<endl;
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1,x,y,ans;i<=q;i++){
		cin>>x>>y,ans=INF;
		for(int xid=0;xid<g[x].size();xid++)for(int yid=0;yid<g[y].size();yid++){
			int xx=g[x][xid].fi,yy=g[y][yid].fi,W=g[x][xid].se+g[y][yid].se;
			ans=min(ans,f[xx][yy]+W+w[x]+w[y]); 
		}
		cout<<ans<<endl;
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
