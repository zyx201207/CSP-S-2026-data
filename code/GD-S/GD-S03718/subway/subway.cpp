#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
const int N=505,M=5e5+5,INF=1e18;
int c,n,m,d,q,w[M],dis[N][N];
vector<pair<int,int> >ug[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1,k,x,t;i<=n;++i){
		cin>>k;
		while(k--){
			cin>>x>>t;
			ug[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)dis[i][j]=INF;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<(int)ug[i].size();++j){
			for(int l=0;l<(int)ug[i].size();++l){
				if(l^j){
					int u=ug[i][j].first,v=ug[i][l].first;
					int w1=ug[i][j].second,w2=ug[i][l].second;
					dis[u][v]=dis[v][u]=min(dis[u][v],w1+w2);
				}
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==j||i==k||j==k)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]); 
			}
		}
	}
	while(q--){
		int u,v,ans=INF;
		cin>>u>>v;
		for(int i=0;i<(int)ug[u].size();++i){
			for(int j=0;j<(int)ug[v].size();++j){
				int x=ug[u][i].first;
				int y=ug[v][j].first;
				ans=min(ans,dis[x][y]+ug[u][i].second+ug[v][j].second);
			}
			if(!ans)break;
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}

// 76~100pts
