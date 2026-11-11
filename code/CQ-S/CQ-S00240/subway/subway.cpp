#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long opt,n,m,qt,mx_t,w[N],xb[N],a[N][25],t[N][25],dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>opt>>m>>n>>mx_t>>qt;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		int cnt;
		cin>>cnt;
		for(int j=1;j<=cnt;j++){
			long long x,v;
			cin>>x>>v;
			xb[x]++;
			a[x][xb[x]] = i;
			t[x][xb[x]] = v;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j] = 1e18;
		}
		dis[i][i] = 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=xb[i];j++){
			for(int k=1;k<=xb[i];k++){
				long long x = a[i][j], y = a[i][k];
				dis[x][y] = min(t[i][j]+t[i][k],dis[x][y]);
				dis[y][x] = min(t[i][j]+t[i][k],dis[y][x]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	while(qt--){
		long long x,y;
		cin>>x>>y;
		long long ans = 1e18;
		for(int i=1;i<=xb[x];i++){
			for(int j=1;j<=xb[y];j++){
				long long u = a[x][i], v = a[y][j];
				ans = min(ans,dis[u][v]+w[x]+t[x][i]+w[y]+t[y][j]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
210MB
0 2 5 20 2

4 1 9 2 5

3 1 5 2 7 4 6
3 2 3 3 4 5 7

1 3
1 2

*/
