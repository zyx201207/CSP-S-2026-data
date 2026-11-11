#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
queue<int> q;
vector<int> adj[N];
int n, m, a[N], las[N], cnt[N], deg[N], ans[N];
bool flag[N];

void toposort() {
    for (int i = 1; i <= n; i++) cnt[i] = 1; 
    for (int i = 1; i <= n; i++) if (!deg[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]) {
            cnt[v] += cnt[u];
            if (!--deg[v]) q.push(v);
        }
    }
}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) {
        if (!las[a[i]]) flag[i] = true;
        if (!las[a[i]]) adj[i].push_back(i + 1), deg[i + 1]++;
        else adj[i].push_back(las[a[i]]), deg[las[a[i]]]++;
        las[a[i]] = i;
    }
    toposort();
    for (int i = 1; i <= n; i++) if (flag[i]) ans[a[i]] = cnt[i];
    for (int i = 1; i <= m; i++) {
		cout << ans[i];
		if (i != m) cout << " ";
	}
	return 0;
}
