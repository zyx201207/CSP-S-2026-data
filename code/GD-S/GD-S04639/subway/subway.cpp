#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
const int M = 5e2+10;
#define int long long
int c,n,m,d,q;
int w[N],k[N];
vector<pair<int,int> >E[N];
int dis[M][M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1,a,t; j <= k[i]; j++){
			cin >> a >> t;
			E[i+m].push_back({a,t});
			E[a].push_back({i+m,t});
		}
	}
	//n+mµã   2\sumk±ß
	for(int x = 1; x <= n; x++){
		for(int y = 1; y <= n; y++){
			dis[x][y]=1e18;
		}
		dis[x][x]=0;
	}
	for(int u = 1+m; u <= n+m; u++){
		for(auto it : E[u]){
			int x=it.first;
			for(auto itt : E[x]){
				int v=itt.first;
				if(u!=v){
					dis[u-m][v-m]=min(dis[u-m][v-m],it.second+itt.second);
					dis[v-m][u-m]=min(dis[v-m][u-m],it.second+itt.second);
				}
			}
		}
	}
	for(int z = 1; z <= n; z++){
		for(int x = 1; x <= n; x++){
			for(int y = 1; y <= n; y++){
				dis[x][y]=min(dis[x][y],dis[x][z]+dis[z][y]);
			}
		}
	}
	while(q--){
		int x,y;cin >> x >> y;
		int ans=1e18;
		for(auto it : E[x]){
			for(auto itt : E[y]){
				int u=it.first,v=itt.first;
				int res=dis[u-m][v-m];
				res+=it.second;
				res+=itt.second; 
				res+=w[x]+w[y];
				ans=min(ans,res);
			}
		}
		cout << ans << '\n';
	}
}
