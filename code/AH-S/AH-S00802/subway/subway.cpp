#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5,D=25,Mod=998244353;
int w[M],cnt[M],f[N][N];
pair<int,int> g[M][D];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[a][++cnt[a]]={i,t};
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				f[i][j]=4e18;
	for(int i=1;i<=m;i++)
		for(int x=1;x<=cnt[i];x++)
			for(int y=x+1;y<=cnt[i];y++){
				int u=g[i][x].first;
				int v=g[i][y].first;
				int qwq=g[i][x].second;
				int awa=g[i][y].second;
				if(u==v)
					continue;
				f[u][v]=min(f[u][v],qwq+awa);
				f[v][u]=min(f[v][u],qwq+awa);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++){
			if(i==k)
				continue;
			for(int j=1;j<=n;j++){
				if(j==k||j==i)
					continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=4e18;
		int id1,id2;
		for(int u=1;u<=cnt[x];u++)
			for(int v=1;v<=cnt[y];v++){
				int qwq=g[x][u].first;
				int awa=g[y][v].first;
				int xx=g[x][u].second;
				int yy=g[y][v].second;
				if(f[qwq][awa]<ans){
					ans=f[qwq][awa];
					id1=xx;
					id2=yy;
				}
				else if(f[qwq][awa]==ans&&xx+yy<id1+id2){
					id1=xx;
					id2=yy;
				}	
			}
		ans+=w[x]+w[y]+id1+id2;
		cout<<ans<<"\n";
	}
	return 0;
}
