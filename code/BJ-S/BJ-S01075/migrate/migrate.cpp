#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 5, B = 5005;
const ll INF = 4e18;
ll x[N], dp[B][B], cnt[B][B], n, d;
inline void floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dp[i][k] + dp[k][j] < dp[i][j]) cnt[i][j] = cnt[i][k] * cnt[k][j], dp[i][j] = dp[i][k] + dp[k][j];
                else if(dp[i][k] + dp[k][j] == dp[i][j] && cnt[i][j] <= 2) cnt[i][j] += cnt[i][k] * cnt[k][j];
            }
        }
    }
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int c, _;
    cin >> c >> _;
    while(_--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> x[i];
        if(c == 11 || c == 12){
            if(n == 1){
                cout << "0\n";
                continue;
            }
            if(d / (x[2] - x[1]) < 2){
                cout << "0\n";
                continue;
            }
            cout << max(0ll, n - d / (x[2] - x[1]) * 2 + 1) << "\n";
            continue;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) dp[i][j] = (abs(x[i] - x[j]) <= d ? 1 : INF), cnt[i][j] = (abs(x[i] - x[j]) <= d);
            dp[i][i] = 0, cnt[i][i] = 0;
        }
        floyd();
        ll ans = 0;
        for(int i = 1; i <= n; i++) for(int j = i + 1; j <= n; j++) ans += (cnt[i][j] == 2);
        cout << ans << "\n";

    }
    return 0;
}