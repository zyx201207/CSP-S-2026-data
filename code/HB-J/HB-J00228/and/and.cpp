#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, v, a[200010], dp[200010] = {-1};
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> v;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) // number
        for (int j = v; j >= 1; j --){ // space left
            dp[j] = max(dp[j], dp[j - 1] & a[i]);
        }
    cout << dp[v];
    return 0;
}
