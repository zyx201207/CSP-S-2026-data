#include <bits/stdc++.h>
using namespace std;
//int a[5] = {0, 1, 3, 3, 4};

const int N = 5e5 + 5;
int a[N], v[N], ans[N];
int vis[N];

int main() {
    freoprn("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    //cout << lower_bound(a + 0, a + 5, 2) - a;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int l = 1; l <= n; l++) {
        memset(vis, 0, sizeof(vis));
        memset(v, 0, sizeof(v));
        int r = 0;
        for (int i = l; i <= n; i++) {
            if (vis[a[i]] == 0) {
                r += 1;
                v[r] = a[i];
                vis[a[i]] += 1;
            } else {
                int r1 = lower_bound(v + 1, v + r + 1, a[i]) - v;
                for (int j = r1 + 1; j <= r; j++) {
                    vis[v[j]] = 0;
                }
                r = r1;
            }
        }
        //for (int i = 1; i <= r; i++) {
            //cout << v[i] << " ";
        //}
        //cout << "\n";
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= r; j++) {
                if (v[j] == i) {
                    ans[i]++;
                    break;
                }
            }
            //if (v[lower_bound(v + 1, v + r + 1, i) - v] == i) {
                
                //ans[i]++;
            //}
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}