#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define int long long
using namespace std;
int c,n,m,d,q,w[500010];
struct Node{
	int x,len;
};
vector<Node> vv[500010];
int dis[510][510];
signed main(void) {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) cin >> w[i];
	for (int k,i=1;i<=n;i++) {
		cin >> k;
		for (int a,t,j=1;j<=k;j++) {
			cin >> a >> t;
			vv[a].push_back(Node{i,t});
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			if (i==j) dis[i][j]=0;
			else dis[i][j]=1e18;
		}
	}
	for (int i=1;i<=m;i++) {
		int sz=vv[i].size();
		for (int k1=0;k1<sz;k1++) {
			for (int k2=k1+1;k2<sz;k2++) {
				int u=vv[i][k1].x,v=vv[i][k2].x;
				int len1=vv[i][k1].len,len2=vv[i][k2].len;
				dis[u][v]=min(dis[u][v],len1+len2);
				dis[v][u]=min(dis[v][u],len1+len2);
			}
		}
	}
	for (int k=1;k<=n;k++) {
		for (int i=1;i<=n;i++) {
			if (k==i) continue;
			for (int j=1;j<=n;j++) {
				if (k==j||i==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for (int x,y;q--;) {
		cin >> x >> y;
		int ans=1e18;
		for (auto it:vv[x]) {
			for (auto it2:vv[y]) {
				int u=it.x,v=it2.x;
				int len1=it.len,len2=it2.len;
				ans=min(ans,dis[u][v]+w[x]+w[y]+len1+len2);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
