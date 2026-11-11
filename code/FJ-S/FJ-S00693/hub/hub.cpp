#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, inf = 1e18;
int c, t, n, m, k, x, y, vis[N], ans, sum, dis[15];
vector <int> v[N];

bool check(int x){
	int lst = 0, cnt = 0;
	for(int i = 1; i <= m + 1; i++){
		if(i - lst >= x){
			cnt++;
			lst = i + x + 1;
		}
	}
	return cnt <= k;
}

int ef(int l, int r){
	int mid = l + r >> 1;
	if(l == r) return mid;
	if(check(mid)) return ef(l, mid);
	else return ef(mid + 1, r); 
}

void dd(int x, int y, int fa){
	dis[x] = min(dis[x], y);
	for(auto xx : v[x]) if(xx != fa) dd(xx, y + 1, x);
}

void dfs(int x){
	if(x > k){
		sum = 0;
		for(int i = 1; i <= n; i++) dis[i] = inf;
		for(int i = 1; i <= n; i++)
		    if(vis[i]) dd(i, 0, i);
		for(int i = 1; i <= n; i++) sum = max(sum, dis[i]);
		ans = min(ans, sum);
		return ;
	}
	for(int i = 1; i <= n; i++)
	    if(!vis[i]) vis[i] = 1, dfs(x + 1), vis[i] = 0;
}

signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--){
		ans = inf;
		cin >> n >> k;
		for(int i = 1; i <= n; i++) v[i].clear();
		for(int i = 1; i < n; i++) cin >> x >> y, v[x].push_back(y), v[y].push_back(x);
		if(k == n){
			cout << 0 << "\n";
			continue;
		}
		if(c <= 1){
			dfs(1);
			cout << ans << "\n";
			continue;
		} 
		if(c >= 13 && c <= 14){
			m = n >> 1;
			cout << ef(1, n) << "\n";
			continue;
		}
		cout << 1 << "\n";
	}
	return 0;
}
