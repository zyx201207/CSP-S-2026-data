#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e2+5,MAXM=5e5+5,INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[MAXM];
struct Subway{
	int v,w;
};
vector<Subway> rail[MAXM];//每个地铁站所连的线路编号、通行时间 
int mp[MAXN][MAXN];//多源最短路 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			rail[a].push_back((Subway){i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			mp[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++){
		for(int a=0;a<rail[i].size();a++){
			for(int b=0;b<rail[i].size();b++){
				if(a==b)continue;
				int u=rail[i][a].v,v=rail[i][b].v;
				int wu=rail[i][a].w,wv=rail[i][b].w;
				mp[u][v]=min(mp[u][v],wu+wv);
				mp[v][u]=min(mp[v][u],wu+wv);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		int ans=INF;
		for(Subway u:rail[x]){
			for(Subway v:rail[y]){
				ans=min(ans,mp[u.v][v.v]+u.w+v.w);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
