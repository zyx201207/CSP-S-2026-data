#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5010;
int tc, t, n, dist[N];
ll way[N];
ll d, a[N];
vector<int> e[N];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> tc >> t;
	for(; t--; ){
		cin >> n >> d;
		for(int i= 1; i <= n; i++)
			cin >> a[i], e[i].clear();
		int ans = 0;
		/*for(int i= 1; i <= n; i++){
			int lst = -1;
			for(int j = i; j <= n; ){
				int pre = j;
				int pos = upper_bound(a + 1, a + n + 1, a[j] + d) - a - 1;
				for(int k = pre + 1; k <= pos; k++){
					int it = lower_bound(a + 1, a + n + 1, a[k] - d) - a;
					if(lst - 1 == it && a[k] - a[it] <= d)
						++ans;
				}
				if(pre == pos) break;
				j = pos;
				lst = pos;
			}
		} */
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				if(a[j] - a[i] <= d)
					e[i].push_back(j);
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++)
				dist[j] = 1e9, way[j] = 0;
			dist[i] = 0, way[i] = 1;
			for(int j = i; j <= n; j++){
				for(auto u : e[j])
					if(dist[j] + 1 < dist[u]){
						dist[u] = dist[j] + 1;
						way[u] = way[j];
					} else if(dist[j] + 1 == dist[u])
						++way[u];
			}
			for(int j = i + 1; j <= n; j++)
				ans += (way[j] == 2);
		}
		cout << ans << '\n';
	}
	return 0;
} 
