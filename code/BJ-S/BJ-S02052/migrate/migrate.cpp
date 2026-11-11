#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 0x3f3f3f3f3f3f;

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    while(t--) {
        int ans = 0;
        vector <int> vec;
        int dist[210][210];
        memset(dist, inf, sizeof(dist));
        int n, d;
        cin >> n >> d;
        vec.resize(n + 5);
        for(int i = 1; i <= n; i++) {
            int t;
            cin >> t;
            vec[i] = t;
        }
        for(int len = 2; len <= n; len++) {
            for(int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                if(vec[j] - vec[i] <= d) {
                    dist[i][j] = 1;
                    continue;
                }
                int tot = 0;
                for(int k = i + 1; k <= j - 1; k++) {
                    if(dist[i][k] + dist[k][j] == dist[i][j] && dist[i][k] != inf && dist[k][j] != inf) tot++;
                    else if(dist[i][k] + dist[k][j] < dist[i][j] && dist[i][k] != inf && dist[k][j] != inf) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        tot = 1;
                    }
                }
                //cout << i << " " << j << " " << tot << endl;
                if(tot == 2) {
                    ans++;
                    //cout << i << " " << j << endl;
                }
            }
        }
        cout << ans << endl;
    }
}
