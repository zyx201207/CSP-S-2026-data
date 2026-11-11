#include<bits/stdc++.h>
using ll = long long;
using namespace std;

ll n, m, ans;
int a[200005];
bool vis[200005];

void dfs(ll res, int dep) {
    if(dep == m) {
        ans = max(ans, res);
        return ;
    }
    for(int i = 1;i <= n;i ++) {
        if(vis[i] == 0) {
            vis[i] = 1;
            if(res == -1) {
                dfs(a[i], dep + 1);
            }
            else {
                dfs(res & a[i], dep + 1);
            }
            vis[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
    }
    if(m == n) {
        ans = a[1];
        for(int i = 2;i <= n;i ++) {
            ans = ans & a[i];
        }
        cout << ans << "\n";
        return 0;
    }
    dfs(-1, 0);
    cout << ans << "\n";
    return 0;
}

