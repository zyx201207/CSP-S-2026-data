#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 5 * 1e5 + 5,inf = 1e18;
int c,n,m,d,q;
int w[maxn];

int a[maxn],t[maxn],p;
int dis[1005][1005];
void solve1() {
	for(int i = 1;i <= m;i ++) {
		for(int j = 1;j <= m;j ++) {
			dis[i][j] = inf;
		}
	}
	
	for(int k = 1;k <= n;k ++) {
		cin >> p;
		for(int i = 1;i <= p;i ++) {
			cin >> a[i] >> t[i];
		}
		if(p == 1) continue;
		
		for(int i = 1;i <= p;i ++) {
			for(int j = 1;j <= p;j ++) {
				if(i == j) continue;
				
				dis[a[i]][a[j]] = min(dis[a[i]][a[j]],t[i] + t[j]);
				dis[a[j]][a[i]] = dis[a[i]][a[j]];
			}
		}
	}
	
	for(int k = 1;k <= m;k ++) {
		for(int i = 1;i <= m;i ++) {
			for(int j = 1;j <= m;j ++) {
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	
	int x,y;
	while(q --) {
		cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] << '\n';
	}
}

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++) {
		cin >> w[i];
	}
	
	solve1();
	
	
	return 0;
}
