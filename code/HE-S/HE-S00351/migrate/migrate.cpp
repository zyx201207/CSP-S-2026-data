#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000010];
int q[2000010],dist[2000010],g[200010];
int n;
long long d;
inline void bfs(int p) {
	int r = 0,f = 1;
	q[++r] = p;
	dist[p] = 0;
	while(f <= r) {
		int x = q[f++];
		for(int i = x + 1;i <= n && a[i] - a[x] <= d;i++) {
			if(dist[i] == -1) {
				dist[i] = dist[x] + 1;
				q[++r] = i;
			} else if(dist[i] == dist[x] + 1) {
				g[i]++;
			}
		}
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1;i <= n;i++) {
			cin >> a[i];
		}
		long long ans = 0;
		for(int i = 1;i <= n;i++) {
			memset(q,0,sizeof(q));
			memset(dist,-1,sizeof(dist));
			memset(g,0,sizeof(g));
			bfs(i);
			for(int j = i + 1;j <= n;j++) {
				if(g[j] == 1) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
