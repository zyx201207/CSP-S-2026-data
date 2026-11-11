#include<bits/stdc++.h>
#define ll long long
#define pli pair<ll, int>
using namespace std;
const ll inf = 1e18;
ll c, t, n, d, a[2000005], dis[2000005], cnt[2000005], farthest[2000005], ans;
int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; ++i){
			cin >> a[i];
		} 
		for(int i = 1; i <= n; ++i){
			int l = i, r = n, ans;
			while(l <= r){
				int mid = l+r>>1;
				if(a[mid]-a[i] <= d){
					l = mid+1;
					ans = mid;
				}else r = mid-1;
			}
			farthest[i] = ans;
		}
		ans = 0;
		for(int i = 1; i <= n; ++i){
			fill(dis+i, dis+n+1, inf);
			dis[i] = 0;
			priority_queue<pli, vector<pli>, greater<pli>> q;
			q.push({0, i});
			while(!q.empty()){
				int u = q.top().second;
				ll d = q.top().first;
				q.pop();
				if(d > dis[u]) continue;
				for(int v = u+1; v <= farthest[u]; ++v){
					ll w = v-u;
					if(dis[v] >= dis[u]+w){
						if(dis[v] > dis[u]+w) cnt[v] = 1;
						else ++cnt[v];
						dis[v] = dis[u]+w;
						q.push({dis[v], v});
					}
				}
			}
			for(int j = i+1; j <= n; ++j){
				if(cnt[j] == 2){
					++ans;
				} 
				cnt[j] = 0;
			}
		}
		cout << ans << '\n';
		//È¼¾¡ÁË 0pts
	}
}
