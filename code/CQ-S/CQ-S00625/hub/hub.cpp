#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, k, dis[N], cnt, dp[N];
bool col[N];
pair <int, int> E[N];
vector <int> G[N];
vector <int> stk;
void Mark(int u) {
    if (!col[u]) {
        col[u] = true;
        cnt++;
    }
}
void dfs(int u, int cut, int fa, int d, int mid) {
    if (stk.size() >= mid + 1)
        Mark(stk[stk.size() - mid - 1]);
    for (int v : G[u]) {
        if (((u == E[cut].first && v == E[cut].second) || (u == E[cut].second && v == E[cut].first)))
            continue;
        if (v == fa)
            continue;
        stk.push_back(v);
        dfs(v, cut, u, d + 1, mid);
        stk.pop_back();
    }
}
int dfs2(int u, int cut, int fa) {
    if (!u)
        return 0;
    int ret = dp[u];
    for (int v : G[u]) {
        if (((u == E[cut].first && v == E[cut].second) || (u == E[cut].second && v == E[cut].first)))
            continue;
        if (v == fa)
            continue;
        ret = min(ret, dfs2(v, cut, u));
    }
    return ret;
}
bool Check(int cut, int mid) {
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++)
            col[j] = false;
        stk.push_back(i);
        cnt = 0;
        Mark(i);
        dfs(i, cut, -1, 0, mid);
        stk.pop_back();
        dp[i] = cnt;
    }
    int val = dfs2(E[cut].first, cut, -1) + dfs2(E[cut].second, cut, -1);
    //cout << "Cut = " << cut << " Mid = " << mid << " " << val << "\n";
    // for (int i = 1;i <= n;i++)
    //     cout << dp[i] << " ";
    // cout << "\n";
    return  val <= k;
}
inline void Solve() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++)
        G[i].clear();
    for (int i = 1;i < n;i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        E[i] = { u,v };
    }
    int mi = INT_MAX;
    E[0].first = 1;
    E[0].second = 0;
    for (int i = 0;i < n;i++) {
        //break E[i].
        int l = 0, r = n, ans;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (Check(i, mid)) {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        mi = min(mi, ans);
    }
    cout << mi << "\n";
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--)
        Solve();
    return 0;
}