#include<bits/stdc++.h>
using namespace std;

const int N = 5 * 1e5 + 5;
const long long INF = 1e18;
int c,n,m,d,q;
int w[505],k[505],a[505][505],t[505][505];
long long dis[505][505];
struct Station{
	int lin,tim;
};
vector<Station> g[N];
void Floyd(){
	for (int k = n;k >= 1;k--){
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= n;j++){
				dis[i][j] = min(dis[i][k] + dis[k][j],dis[i][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i = 1;i <= m;i++) cin>>w[i];
	for (int i = 1;i <= n;i++){
		cin>>k[i];
		for (int j = 1;j <= k[i];j++){
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= n;j++) dis[i][j] = INF;
		dis[i][i] = 0;
	}
	for (int i = 1;i <= m;i++){
		for (int j = 0;j < g[i].size();j++){
			for (int x = j + 1;x < g[i].size();x++){
				int u = g[i][j].lin,v = g[i][x].lin;
				dis[v][u] = dis[u][v] = min((long long)g[i][j].tim + g[i][x].tim,dis[u][v]);
			}
		}
	}
	Floyd();
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans = INF;
		for (int i = 0;i < g[x].size();i++){
			for (int j = 0;j < g[y].size();j++){
				//cout<<g[x][i].lin<<" "<<g[x][j].lin<<" "<<dis[g[x][i].lin][g[y][j].lin]<<" "<<ans<<endl;
				//cout<<g[x][i].tim + g[y][j].tim<<endl;
				ans = min(ans,dis[g[x][i].lin][g[y][j].lin] + (long long)g[x][i].tim + g[y][j].tim);
			}
		}
		ans += (w[x] + w[y]);
		cout<<ans<<endl;
	}
}
