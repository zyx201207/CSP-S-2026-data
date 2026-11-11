#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;
int c, t;
int n, k;
vector <int> G[N];
namespace dfs_c_le_3 {
    bool use[25];
    bool vis[25];
    int dis[25];
    int ans = inf;
    queue <int> q;
    bool check() {
        queue <int> q;
        int cnt = 0;
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++) {
            if (use[i] == 1) {
                if (!vis[i]) {
                    cnt++;
                    q.push(i);
                    vis[i] = 1;
                    while (!q.empty()) {
                        int p = q.front();
                        q.pop();
                        for (int v : G[p]) {
                            if (use[v] && (vis[v] == 0)) {
                                vis[v] = 1;
                                q.push(v);
                            }
                        }
                    }
                }
            }
        }
        if (cnt > 2) return 0;
        return 1;
    }
    void Update() {
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);
        queue <int> q;
        for (int i = 1; i <= n; i++) {
            if (use[i] == 1) {
                q.push(i);
                vis[i] = 1;
                dis[i] = 0;
            }
        }
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            for (int v : G[p]) {
                if (vis[v] == 0) {
                    vis[v] = 1;
                    dis[v] = dis[p] + 1;
                    q.push(v);
                }
            }
        }
        int now_mx = 0;
        for (int i = 1; i <= n; i++) {
            now_mx = max(now_mx, dis[i]);
        }
        ans = min(ans, now_mx);
        return ;
    }
    void dfs(int now, int step) {
        if (now > n) {
            if (step != k) return ;
            if (check()) {
                Update();
            }
            return ;
        }
        if (step < k) {
            use[now] = 1;
            dfs(now + 1, step + 1);
            use[now] = 0;
        }
        dfs(now + 1, step);
    }
    void work() {
        ans = inf;
		memset(vis, 0, sizeof vis);
		memset(dis, 0, sizeof dis);
		memset(use, 0, sizeof use);
		dfs(1, 0);
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	if (c <= 3) {
        while (t--) {
            cin >> n >> k;
            for (int i = 1; i <= n; i++) {
                G[i].clear();
            }
            for (int i = 1; i < n; i++) {
                int x, y;
                cin >> x >> y;
                G[x].push_back(y);
                G[y].push_back(x);
            }
            dfs_c_le_3::work();
            cout << dfs_c_le_3::ans << "\n";
        }
	}
	return 0;
}
