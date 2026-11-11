#include<bits/stdc++.h>
using namespace std;
int w[500005];
int a[500005];
struct e{
	int v,w;
};
vector<e> g[2*500005];
int dist[500005][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
		for(int j=1;j<=m;j++){
			dist[i][j] = INT_MAX/2;
		}
		dist[i][i]=0;
	} 
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int t;
			cin >> a[j] >> t;
			g[n+a[j]].push_back({a[j],t});
			g[a[j]].push_back({n+a[j],t});
		}
		for(int j=1;j<=k;j++)
			for(int o=j+1;o<=k;o++)
				g[a[j]].push_back({a[o],0});
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j && j==k) continue;
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << dist[x+n][y+n]+w[x]+w[y] << endl;
	}
	return 0;
}
