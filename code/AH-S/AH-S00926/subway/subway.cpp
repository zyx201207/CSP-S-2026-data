#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,add[500005],dis[505][505],b[505][505],vis[505];
struct node{
	int id,dis;
};
vector<node>ve[500005];
void dijkstra(int id){
	memset(vis,0,sizeof(vis));
	dis[id][id] = 0;
	for(int i = 1;i<=n;i++){
		int minn,w;
		minn = 1e18;
		for(int j = 1;j<=n;j++){
			if(vis[j]){
				continue;
			}
			if(dis[id][j]<minn){
				minn = dis[id][j];
				w = j;
			}
		}
		vis[w] = 1;
		for(int j = 1;j<=n;j++){
			if(vis[j]){
				continue;
			}
			if(dis[id][w]+b[w][j]<dis[id][j]){
				dis[id][j] = dis[id][w]+b[w][j];
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>add[i];
	}
	for(int i = 1;i<=n;i++){
		int l;
		cin>>l;
		for(int j = 1;j<=l;j++){
			int to,w;
			cin>>to>>w;
			ve[to].push_back({i,w});
		}
	}
	memset(b,0x3f,sizeof(b));
	for(int i = 1;i<=m;i++){
		int l;
		l = ve[i].size();
		for(int j = 0;j<l;j++){
			for(int k = j+1;k<l;k++){
				node h1,h2;
				h1 = ve[i][j];
				h2 = ve[i][k];
				b[h1.id][h2.id] = b[h2.id][h1.id] = min(b[h1.id][h2.id],h1.dis+h2.dis);
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i = 1;i<=n;i++){
		dijkstra(i);
	}
	while(q--){
		int u,v,ans;
		cin>>u>>v;
		ans = 1e18;
		int l1,l2;
		l1 = ve[u].size();
		l2 = ve[v].size();
		for(int i = 0;i<l1;i++){
			for(int j = 0;j<l2;j++){
				node h1,h2;
				h1 = ve[u][i];
				h2 = ve[v][j];
				ans = min(ans,dis[h1.id][h2.id]+h1.dis+h2.dis);
			}
		}
		ans = ans+add[u]+add[v];
		cout<<ans<<"\n";
	}
	return 0;
}


