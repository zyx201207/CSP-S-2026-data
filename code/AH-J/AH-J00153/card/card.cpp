# include <bits/stdc++.h>
using namespace std;
int n , m , a[500005];
vector <int> ans (300005);
int main () {
    freopen ("card.in" , "r" , stdin);
    freopen ("card.out" , "w" , stdout);
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    cin >> n >> m;
    vector <bool> vis (300005);
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        if (vis[a[i]]) {
            for (int j = i - 1;j >= 1;j --) {
                vis[a[j]] = false;
                if (a[j] == a[i]) break;
            }
        }
        vis[a[i]] = true;
    }
    for (int i = 1;i <= m;i ++) {
        if (vis[i]) ans[i] ++;
    }
    for (int i = 2;i <= n;i ++) {
        a[i - 1] = -1;
        vector <bool> vis(300005);
        for (int j = i;j <= n;j ++) {
            if (vis[a[j]]) {
                for (int k = j - 1;k >= i;k --) {
                    vis[a[k]] = false;
                    if (a[k] == a[j]) break;
                }
            }
            vis[a[j]] = true;
        }
        for (int j = 1;j <= m;j ++) {
            if (vis[j]) ans[j] ++;
        }
    }
    for (int i = 1;i <= m;i ++) {
        cout << ans[i] << " ";
    }
    return 0;
}
