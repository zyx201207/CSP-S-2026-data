#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MAXN = 5005, INF = 0x3f3f3f3f;

long long n, k, ans, dis[MAXN][MAXN];
vector<int> sides[MAXN];

vector<int> insert(vector<int> a, int v) {
    a.push_back(v);
    return a;
}

void dijk(long long s) {
    vector<bool> vising(n, true);
    while (true) {
        long long mins = -1, minv = INF;
        for (int i = 0;i < n;++i) {
            if (vising[i] && dis[s][i] < minv) {
                mins = i;
                minv = dis[s][i];
            }
        }
        if (mins == -1) break;
        vising[mins] = false;
        for (int i = 0;i < n;++i) {
            if (dis[s][i] > dis[s][mins] + dis[mins][i]) {
                dis[s][i] = dis[s][mins] + dis[mins][i];
                vising[i] = true;
            }
        }
    }
}

void check(vector<int> a0, vector<int> a1) {
    for (int i = 0;i < n;++i) {
        for (auto v0: sides[i]) {
            dis[i][v0] = 1;
            dis[v0][i] = 1;
        }
    }
    for (int i = 0;i < n;++i) {
        dijk(i);
    }
    long long mmv = 0;
    for (int i = 0;i < n;++i) {
        long long minv = INF;
        for (auto v0: a0) {
            minv = min(minv, dis[i][v0]);
        }
        for (auto v0: a1) {
            minv = min(minv, dis[i][v0]);
        }
        mmv = max(mmv, minv);
    }
    ans = min(ans, mmv);
}

void dfs(vector<int> a0, vector<int> a1) {
    if (a0.size() + a1.size() == k) {
        check(a0, a1);
        return;
    }
    for (auto v0: a0) {
        for (auto v1: sides[v0]) {
            if (find(a0.begin(), a0.end(), v1) != a0.end() || find(a1.begin(), a1.end(), v1) != a1.end()) continue;
            dfs(insert(a0, v1), a1);
        }
    }
    for (auto v0: a1) {
        for (auto v1: sides[v0]) {
            if (find(a0.begin(), a0.end(), v1) != a0.end() || find(a1.begin(), a1.end(), v1) != a1.end()) continue;
            dfs(insert(a0, v1), a1);
        }
    }
}

void xmain() {
    ans = INF;
    cin >> n >> k;
    for (int i = 0;i < n;++i) {
        sides[i].clear();
    }
    for (int i = 0;i < n - 1;++i) {
        int u, v;
        cin >> u >> v;
        sides[u].push_back(v);
        sides[v].push_back(u);
    }
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) {
            if (i != j) dfs({i}, {j});
        }
    }
    cout << ans << "\n";
}

int main() {
    freopen("hub.in",  "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, t;
    cin >> c >> t;
    while (t--) xmain();
}