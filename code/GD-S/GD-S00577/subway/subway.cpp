#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, t, k, x, y, w[500050], id[500050], hc[505][505], f[505][505], b[505], ans=0;
struct qwe{
	int x, z;
}a[500050][25];
struct ewq{
	int i, disi;
	friend bool operator < (ewq x, ewq y) {
		return x.disi>y.disi;
	}
};
priority_queue<ewq>q;
void dijk(int now) {
	for(int i=1; i<=n; i++) f[now][i]=1e18, b[i]=0;
	f[now][now]=0; q.push({now, 0});
	while(!q.empty()) {
		int cur=q.top().i;
		q.pop(); b[cur]=1;
		for(int i=1; i<=n; i++) {
			if(b[i]) continue;
			if(f[now][i]>f[now][cur]+hc[i][cur]) {
				f[now][i]=f[now][cur]+hc[i][cur];
				q.push({i, f[now][i]});
			}
		}
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>t;
	for(int i=1; i<=m; i++) cin>>w[i], id[i]=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) hc[i][j]=hc[j][i]=1e18;
		cin>>k; hc[i][i]=0;
		for(int j=1; j<=k; j++) {
			cin>>x>>y; id[x]++;
			a[x][id[x]].x=i;
			a[x][id[x]].z=y;
		}
	}
	for(int i=1; i<=m; i++) {
		k=id[i];
		for(int l=1; l<k; l++) {
			for(int r=l+1; r<=k; r++) {
				x=a[i][l].x; y=a[i][r].x;
				hc[x][y]=min(hc[x][y], a[i][l].z+a[i][r].z);
				hc[y][x]=hc[x][y];
			}
		}
	}
	for(int i=1; i<=n; i++) dijk(i);
	while(t--) {
		cin>>x>>y; ans=w[x]+w[y];
		int I=id[x], J=id[y], cur=1e18;
		for(int i=1; i<=I; i++) {
			for(int j=1; j<=J; j++) {
				if(a[x][i].x==a[y][j].x) cur=min(cur, a[x][i].z+a[y][j].z);
				else cur=min(cur, a[x][i].z+f[a[x][i].x][a[y][j].x]+a[y][j].z);
			}
		}
		cout<<ans+cur<<"\n";
	}
	return 0;
}

