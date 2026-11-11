#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int c, n, m, d, q;
int w[N];
int x, y;
long long ans;
vector<int>a[505];
vector<int>t[505];
vector<pair<int,int>>b[N];
bool vis[1005][1005];
void dfs(int now, int sum, int last) {
	if (sum > ans) {
		return;
	}
	if (now == y) {
		ans = sum;
		return;
	}
	for(auto i:b[now]) {
		int line = i.first;
		if (last == line) {
			continue;
		}
		int zhan = i.second;
//		if (now == 3 && a[line][zhan+1] == 2) {
//			cout << sum + t[line][zhan] + t[line][zhan + 1]<< '\n';
//		}
		for (int j = 1; j <= a[line][0]; j++) {
//			cout << now << " " << a[line][j] << '\n';
			if (vis[now][a[line][j]] && q < 2000) {
				continue;
			}
			vis[now][a[line][j]] = 1;
			if(a[line][j] == now) {
				continue;
			}
			dfs(a[line][j], sum + t[line][zhan] + t[line][j], line);			
		}
	}
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        a[i].push_back(k);
        t[i].push_back(k);
        for (int j = 1; j <= k; j++) {
            int x1, x2;
            cin >> x1 >> x2;
            a[i].push_back(x1);
            t[i].push_back(x2);
            b[x1].push_back({i,j});
        }
    }
    for (int i = 1; i <= q; i++) {
    	if (q < 2000) memset(vis, 0, sizeof(vis));
		ans = INT_MAX;
    	cin >> x >> y;
    	dfs(x, 0, -1);
    	cout << ans + w[x] + w[y] << '\n';
	}
    return 0;
}
