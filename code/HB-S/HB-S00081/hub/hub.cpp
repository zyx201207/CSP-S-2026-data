#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
vector<int> ed[N];
int n, k;
int dp[N], cnt;
void dfs(int x, int fa, int v) {
    int fl = 0;
    for(auto p : ed[x]) {
        dfs(p, x, v);
        if(dp[x] + dp[p] + 1 > v) {
            ++cnt;
            fl = 1;
        }
        dp[x] = max(dp[x], dp[p] + 1);
    }
    if(fl) dp[x] = 0;
}
void sv() {
    int l = 1, r = n;
    while(l <= r) {
        int mid = (l + r) >> 1;
        for(int i = 1; i <= n; ++i)
            dp[i] = 0;
        cnt = 0;
        dfs(1, 1, mid);
        if(cnt <= 2) r = mid - 1;
        else l = mid + 1;
    }
    printf("%d\n", l);
}
void solve() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) ed[i].clear();
    for(int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        ed[u].push_back(v);
    }
    if(k == 2) sv();
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int T;
    scanf("%*d%d", &T);
    while(T--) solve();
}
