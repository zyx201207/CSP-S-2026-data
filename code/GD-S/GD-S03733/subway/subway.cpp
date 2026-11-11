#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N=5e5+10,M=510; 
int c,n,m,d,Q,w[N],dist[M][M];
vector<pair<int,int>> ds[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,v;cin>>a>>v;
			ds[a].emplace_back(i,v);//表示这个点 a 到 路线 i 的距离 v
		}
		dist[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int S=ds[i].size();
		for(int p1=0;p1<S;p1++){
			int x=ds[i][p1].fi,w1=ds[i][p1].se;
			for(int p2=p1+1;p2<S;p2++){
				int y=ds[i][p2].fi,w2=ds[i][p2].se;
				if(w1+w2<dist[x][y]) dist[x][y]=dist[y][x]=w1+w2;
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	while(Q--){
		int x,y;
		cin>>x>>y;
		int ans=4e18,S1=ds[x].size(),S2=ds[y].size();
		for(int p1=0;p1<S1;p1++){
			for(int p2=0;p2<S2;p2++){
				ans=min(ans,w[x]+w[y]+dist[ds[x][p1].fi][ds[y][p2].fi]+ds[x][p1].se+ds[y][p2].se);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
