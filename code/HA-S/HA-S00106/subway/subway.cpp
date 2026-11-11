#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define int long long
const int M=402,N=202;
int c,n,m,d,Q;
int a[N][M],t[N][M];
int w[M],k[M];
long long dis[N*M];
bool vis[N*M];
vector<pii >v[M*N];
priority_queue<pii,vector<pii >,greater<pii > >q;
long long min_(long long ta,int tb) {
	if (ta>tb) return tb;
	else return ta;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++) {
		cin>>k[i];
		for (int j=1;j<=k[i];j++) {
			cin>>a[i][j]>>t[i][a[i][j]];
			if (j>1) v[(i-1)*m+a[i][j-1]].push_back({0,(i-1)*m+a[i][j]});
		}
	}
	for (int u=1;u<=m;u++) { //meiju ditiezhan
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				if (i==j) continue;
				if (t[i][u]!=0 && t[j][u]!=0) {
					v[(i-1)*m+u].push_back({t[i][u]+t[j][u],(j-1)*m+u});
					v[(j-1)*m+u].push_back({t[i][u]+t[j][u],(i-1)*m+u});
				}
			}
		}		
	}
	while (Q--) {
		int x,y;
		long long ans=LLONG_MAX;
		cin>>x>>y;
//		for (int i=0;i<=N*M;i++) dis[i]=LLONG_MAX;
		memset(dis,0x7f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=n;i++) {
			if (t[i][x]>0) {
//				dis[(i-1)*m+x]=t[i][x];
				q.push({t[i][x],(i-1)*m+x});
			}
		}
		while (!q.empty()) {
			int u=q.top().second,dd=q.top().first;
			q.pop();
			if (vis[u]) continue;
			vis[u]=1;
			for (auto i:v[u]) {
				if (dd+i.first<dis[i.second]) {
					dis[i.second]=dd+i.first;
					q.push({dis[i.second],i.second});
				}
			}
		}
		for (int i=1;i<=n;i++) ans=min_(ans,dis[(i-1)*m+y]+t[i][y]);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}