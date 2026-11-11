#include<bits/stdc++.h>
#define int long long
using namespace std;

int c, t, n, d, x[305];

signed main() {

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> c >> t;
    while(t--) {
        int ans = 0;
        cin >> n >> d; 
        for(int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        for(int u = 1; u < n; u++) {
            for(int v = u + 1; v <= n; v++) {
                bool isReachable = true;
                int now = u ,lst = u;
                while(x[now] + d < x[v]) {
                    if(x[now] + d < x[now + 1]) {
                        isReachable = false;
                        break;    
                    }
                    lst = now, now = upper_bound(x + u, x + v + 1, x[now] + d) - x - 1;
                }
                if(!isReachable) break;
                if(now != u && x[now - 1] + d >= x[v] && (now == u + 1 || x[now - 2] + d < x[v])) {
                    if(lst == now || lst == u || x[lst - 1] + d < x[now]) ans++;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}