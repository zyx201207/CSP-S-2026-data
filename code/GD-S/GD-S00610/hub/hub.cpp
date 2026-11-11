#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

const int N=15;
int n, k, c, T;
int fa[N], dis[N][N], cnt[N];
bool p[N];
vector<int> G[N], x;

int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void merge(int x, int y) {
	if(find(x)==find(y)) return ;
	fa[find(x)]=find(y);
}

void solve() {
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) dis[i][j]=100;
		dis[i][i]=0; G[i].clear();
	}
	for(int i=1; i<n; i++) {
		int u, v; cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		dis[u][v]=dis[v][u]=1;
	}
	for(int z=1; z<=n; z++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				for(int k=1; k<=n; k++) {
					if(dis[i][k]+dis[j][k]<=dis[i][j]) dis[i][j]=dis[i][k]+dis[j][k];
				}
			}
		}
	} int ans=10000000;
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=n; j++) cout<<i<<' '<<j<<' '<<dis[i][j]<<'\n';
//	}
	for(int i=0; i<(1<<n); i++) {
		int lst=0, g=0, Y=0;
		for(int j=1; j<=n; j++) fa[j]=j, cnt[j]=p[j]=0;
		for(int j=1; j<=n; j++) {
			if(i&(1<<j-1)) {
				p[j]=1;
				Y++;
			}
		}
		for(int j=1; j<=n; j++) {
			for(int j2=1; j2<=n; j2++) {
				if(dis[j][j2]==1&&p[j]&&p[j2]) merge(j, j2);
			}
		}
		for(int j=1; j<=n; j++) if(!cnt[find(j)]) cnt[find(j)]++, g++;
		if(g>n-k+2||Y!=k) continue; int now=0;
		for(int j=1; j<=n; j++) {
			int res=100000;
			for(int K=1; K<=n; K++) {
				if(p[K]) res=min(res, dis[K][j]);
			}
			now=max(now, res);
		}
		ans=min(ans, now);
	}
	cout<<ans<<'\n';
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>T;
	while(T--) {
		if(c<=3) solve();
	}
	return 0;
}

/*
0 1
8 3
0 1 2 4 8 10 11 13

*/
