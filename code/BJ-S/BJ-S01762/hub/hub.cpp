#include<bits/stdc++.h>
using namespace std;
const int mxN = 3005;
vector<int> g[mxN];
int c, t, n, k;
bool inS[mxN];
void dfs0(int u, int f, int &cnt) {
    if (inS[u] && !inS[f])
        ++cnt;
    for (int &v : g[u])
        if (v != f)
            dfs0(v, u, cnt);
}

int dfs1(int u, int f) {
    if (inS[u]) return 0;
    int ans = 0x3f3f3f3f;
    for (int &v : g[u])
        if (v != f)
            ans = min(ans, dfs1(v, u) + 1);
    return ans;
}
int ans = 0x3f3f3f3f;
void check(set<int> &s) {
    memset(inS, 0, sizeof(inS));
    for (auto &i : s)
        inS[i] = true;
    int cnt = 0;
    dfs0(1, 0, cnt);
    if (cnt > 2)
        return;
    int pa = 0;
    for (int i = 1; i <= n; ++i)
        pa = max(pa, dfs1(i, 0));
    ans = min(pa, ans);
}

void genS(set<int> s) {
    if (s.size() == k) {
        check(s);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (s.find(i) != s.end()) continue;
        s.insert(i);
        genS(s);
        s.erase(i);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> k;
        for (auto &v : g)
            v.clear();
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans = 0x3f3f3f3f;
        genS(set<int>());
        cout << ans << endl;
    }
}
