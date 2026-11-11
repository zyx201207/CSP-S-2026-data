#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000005];
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		int ans = 0;
		for(int i = 1;i <= n;i++) cin >> x[i];
		for(int i = 1;i <= n;i++) {
			vector<int> dist(n+1,8e18),cnt(n+1,0);
			dist[i]=0;
			queue<int> q; q.push(i); cnt[i]=1;
			while(q.size()) {
				int u = q.front(); q.pop();
				for(int j = u;j <= n;j++) {
					if(x[j]-x[u] > d) break;
					if(dist[j] > dist[u] + 1){
						dist[j] = dist[u]+1;
						cnt[j]=cnt[u];
						q.push(j);
					}else if(dist[j] == dist[u] + 1){
						cnt[j] += cnt[u];
					}
				}
			}for(int j = 1;j <= n;j++) ans += cnt[j]==2;
		}cout<<ans<<'\n';
	}
	return 0;
} 
