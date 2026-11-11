#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    long long c, n, m, d, q, w[500005], k[505], a[505][505], t[505][505], x[100005], y[100005], ans[505];
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++){
            cin >> a[i][k[i]] >> t[i][k[i]];
        }
    }
    for(int i = 1; i <= q; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i <= q; i++){
        ans[i] = 0;
    }





    for(int i = 1; i <= q; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}