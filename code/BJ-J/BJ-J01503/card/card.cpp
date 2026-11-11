#include <bits/stdc++.h>
using namespace std;
int main () {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> buc(m+1, 0);
    vector<vector<int>> dp(n+1, vector<int>(0, 0));
    dp[n].push_back(n);
    buc[a[n]] = n;
    vector<int> res(m+1, 0);
    res[a[n]] = 1;
    for (int i = n-1; i >= 1; i--) {
        dp[i] = (buc[a[i]] > 0 ? dp[buc[a[i]]] : dp[i+1]);
        if (buc[a[i]] == 0) dp[i].push_back(i);
        buc[a[i]] = i;
        for (int j = 0; j < dp[i].size(); j++) {
            res[dp[i][j]]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << res[i] << ' ';
    }
    return 0;
}