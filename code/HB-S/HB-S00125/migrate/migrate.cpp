#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
const int INF = 1<<30;
pair<int, int> dp[N];
int a[N];
void solve(){
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i].second = INF;
    }
    dp[1].first = 1, dp[1].second = 0;
    for (int i = 1; i <= n; i++) {
        // if ((i - 1) % d == 0) {
        //     if (dp[i].second != (i - 1) / d) {
        //         dp[i].first = 1;
        //         dp[i].second = (i - 1) / d;
        //     }
        // }
        // if ((i - 1) % d == 0) {
            // if (dp[i].second > dp[i - ]) {
            //     dp[i].first = 1;
            //     dp[i].second = (i - 1) / d;
            // }
        // }

        for (int j = i + 1; j <= n;j++) {
            if (a[j] <= a[i] + d) {
                if (dp[j].second > dp[i].second + 1) {
                    dp[j].second = dp[i].second + 1;
                    dp[j].first = dp[i].first;
                   
                }
                else if (dp[j].second == dp[i].second + 1) {
                    dp[j].first ++;
                }
            } //cout << dp[n].first << ' ' << i << endl;
        }
    }
    int cnt = 0;

    for (int i = 1; i <= n; i++){
        // cout << dp[i].first << ' ';
    //     if (dp[i].first == 2) {
            
    //         cnt += 1 /** (n - i + 1)*/;
    //     }
    // }
        for (int j = 1; j < i; j++) {
            
            //cout << dp[i - j + 1].first << " " << i << " " << j << endl;
            if (dp[a[i] - a[j] + 1].first == 2){
                cnt++;
            }
        }
    }
    // cout << dp[n].second;
    cout << cnt<<endl;
}
int main() {
     freopen("migrate.in", "r", stdin);
     freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--) {
        // if (c == 11 || c == 12) {
        //     solveA();
        // }
        solve();
    }
    return 0;
}