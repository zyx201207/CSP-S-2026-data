#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
//#define DEBUG
#ifdef DEBUG
#define debug(x...) fprintf(stderr,x)
#else
#define debug(x...) ((void)0)
#endif
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<pair<int,int> > rails[500005];
int dis[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			rails[a].push_back({t,i});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
			if(i==j) dis[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
	    for(auto tmp1:rails[i]){
			int u=tmp1.second;
			for(auto tmp2:rails[i]){
				int v=tmp2.second;
				if(u!=v){
					dis[u][v]=min(dis[u][v],tmp1.first+tmp2.first);
				}
			}
		}
	}
	
	//for(int i=1;i<=n;i++){
	//	for(int j=1;j<=n;j++){
	//		debug("%lld %lld %lld\n",i,j,dis[i][j]);
	//	}
	//}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	//for(int i=1;i<=n;i++){
	//	for(int j=1;j<=n;j++){
	//		debug("%lld %lld %lld\n",i,j,dis[i][j]);
	//	}
	//}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=INF;
		for(auto tmp1:rails[x]){
			int u=tmp1.second;
			for(auto tmp2:rails[y]){
				int v=tmp2.second;
				ans=min(ans,w[x]+tmp1.first+dis[u][v]+tmp2.first+w[y]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
