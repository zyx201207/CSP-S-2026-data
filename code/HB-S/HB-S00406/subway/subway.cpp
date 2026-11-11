#include <bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int c, n, m, d, q;
struct edge{
	int v, w;
};
vector<int> belong[20005];
int w[20005];
int t[20005][505];
int dist[505][505];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dist, 0x3f, sizeof(dist));
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++){
		int k;
		cin>>k;
		for(int j=1; j<=k; j++){
			int aij;
			cin>>aij>>t[i][j];
			belong[aij].push_back(i);
		}
	}
	//build the graph
	for(int i=1; i<=m; i++) dist[i][i]=0;
	for(int i=1; i<=m; i++){
		for(auto j: belong[i]){
			for(auto k: belong[i]){
				if(j==k) continue;
				dist[j][k]=min(min(dist[j][k], t[j][i]+t[k][i]), dist[k][j]);
				dist[k][j]=dist[j][k];
			}
		}
	}
	
	//floyd
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dist[i][j]=min(dist[i][k]+dist[k][j], dist[i][j]);
				dist[j][i]=dist[i][j];
			}
		}
	}
	while(q--){
		int x, y;
		cin>>x>>y;
		int ans=0x3f3f3f3f;
		for(auto i: belong[x]){
			for(auto j: belong[y]){
				ans=min(ans, w[x]+w[y]+dist[i][j]+t[i][x]+t[j][y]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
