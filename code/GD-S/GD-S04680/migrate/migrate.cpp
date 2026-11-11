#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2000010;
int C, T, n, D, x[N], d[N], ans, cnt[N];
vector<int> v[N];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0),
	cin.tie(0), cin >> C >> T;
	while (T -- && cin >> n >> D){ans = 0;
		for (int i = 1; i <= n; i ++)
			cin >> x[i], v[i].clear();
		for (int i = 1; i <= n; i ++){
			int l = i + 1, r = n, xx = i;
			while (l <= r){
				int mid = l + r >> 1;
				if (x[mid] - x[i] <= D)
					xx = mid, l = mid + 1;
				else r = mid - 1;
			}for (int k = i + 1; k <= xx; k ++)
				v[i].push_back(k);
		}for (int i = 1; i <= n; i ++){
			queue<int> q;
			for (int j = i; j <= n; j ++)d[j] = 1e18, cnt[j] = 0;
			d[i] = 0, cnt[i] = 1, q.push(i);
			while (q.size()){
				auto u = q.front();q.pop();
				for (auto e : v[u]){
					if (d[e] != 1e18){
						if (d[e] == d[u] + 1)cnt[e] += cnt[u];
						continue;
					}d[e] = d[u] + 1, cnt[e] = cnt[u], q.push(e);
				}
			}for (int j = i + 1; j <= n; j ++)ans += cnt[j] == 2;
		}cout << ans << '\n';
	}return 0;
}
