#include<bits/stdc++.h>
using namespace std;

int n, m, sum;
long long ans = -1e9;
long long a[500005];
bool vis[500005];
vector<long long> d;

void dfs(long long res, long long cnt) {
    if(res > m) {
        ans = max(ans, cnt - 1);
        return ;
    }
    if(res == m) {
        ans = max(ans, cnt);
        return ;
    }
    for(int i = 0;i < d.size();i ++) {
        if(vis[i] == 0) {
            vis[i] = 1;
            dfs(res + d[i], cnt + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;i ++) {
        d.clear();
        memset(vis, 0, sizeof(vis));
        for(int j = 1;j <= n;j ++) {
            if(a[i] >= a[j]) {
                d.push_back(abs(a[i] - a[j]));
            }
            sum += abs(a[i] - a[j]);
        }
        if(sum <= m) {
            ans = n;
        }
        dfs(0, 0);
    }
    cout << ans << "\n";
    return 0;
}
