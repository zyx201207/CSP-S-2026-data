#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int maxn=2e4+510;
const LL INF=1e8;
int c, n, m, d, q;
LL a[maxn];
int dist[maxn][maxn];
int dg[maxn];
void Floyd(){
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=m+n;i++){
			if(i==k)continue;
			for(int j=1;j<=m+n;j++){
				if(j==k || j==k)continue;
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=0;i<=m+n;i++){
		dist[i][i]=0;
		for(int j=0;j<=m+n;j++){
			if(i==j)continue;
			dist[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++){
		LL w;
		cin >> w;
		a[i]=w;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		int a, w;
		for(int j=1;j<=k;j++){
			cin >> a >> w;
			dg[a]++;
			dist[m+i][a]=w;
			dist[a][m+i]=w;
		}
	}
	Floyd();
	while(q--){
		int u, v;
		cin >> u >> v;
		cout << dist[u][v]+a[u]+a[v] << '\n';
	}
	return 0;
}
