#include <bits/stdc++.h>
#define int long long
#define N 610
using namespace std;
int c, n, m, d, q, dp[N][N], t[N], a[N][N], temp1[N], temp2[N];
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, 0x3f, sizeof(dp));
    memset(a, 0x3f, sizeof(a));
    cin >> c >> n >> m >> d >> q;
    swap(n, m);
    for(int i = 1; i <= n; i++){
        cin >> t[i];
    }
    /*
    int cur = n;
    while(m--){
        ++cur;
        int k;
        cin >> k;
        for(int i = 1; i <= k; i++){
            int id, w;
            cin >> id >> w;
            a[cur][id] = min(w, a[cur][id]);
            a[id][cur] = min(w, a[id][cur]);
        }
    }
    for(int i = 1; i <= cur; i++){
        dp[i][i] = 0;
    }
    for(int i = 1; i <= cur; i++){
        for(int j = 1; j <= cur; j++){
            if(i == j){
                continue;
            }
            dp[i][j] = a[i][j];
        }
    }
    for(int k = 1; k <= cur; k++){
        for(int i = 1; i <= cur; i++){
            for(int j = 1; j <= cur; j++){
                if(i == j || j == k || i == k){
                    continue;
                }
                dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
            }
        }
    }
    */
    while(m--){
        int k;
        cin >> k;
        for(int i = 1; i <= k; i++){
            cin >> temp1[i] >> temp2[i];
        }
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= k; j++){
                if(i == j){
                    continue;
                }
                a[temp1[i]][temp1[j]] = min(temp2[i] + temp2[j], a[temp1[i]][temp1[j]]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        dp[i][i] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                continue;
            }
            dp[i][j] = a[i][j];
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j || j == k || i == k){
                    continue;
                }
                dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
            }
        }
    }
    while(q--){
        int b, e;
        cin >> b >> e;
        cout << dp[b][e] + t[b] + t[e] << "\n";
    }
    return 0;
}
