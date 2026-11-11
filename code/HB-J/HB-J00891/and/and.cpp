#include <bits/stdc++.h>
using namespace std;

freopen("and.in", "r", stdin);
freopen("and.out", "w", stdout);

int main(){
    int a[200000 + 10], dp[200000 + 10], m, n;
    cin >> m >> n;
    for(int i = 1; i <= m; i++) cin >> a[i];
    for(int i = 1; i <= m; i++){
        dp[i] = max(dp[i], a[i] | a[i + 1]);
    }
    cout << dp[m];
    return 0;
}
