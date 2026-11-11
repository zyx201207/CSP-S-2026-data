#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int M = 2e3 + 10;

int n, m, a[N], mx[N], all[N], ans;
int dp[M][M];

bool f = 1;

set<int> st;

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i <= 20; i++) st.insert(pow(2, i) - 1);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        mx[i] = max(mx[i - 1], a[i]);
        if (st.find(a[i]) == st.end()) f = 0;
    }
    if (f){
        sort(a + 1, a + n + 1, greater<int>());
        cout << a[m] << '\n';
        return 0;
    }
    all[1] = a[1];
    for (int i = 2; i <= n; i++) all[i] = all[i - 1] & a[i];
    if (m == 1){
        cout << mx[n] << '\n';
        return 0;
    }
    if (m == n){
        cout << all[n] << '\n';
        return 0;
    }
    if (m == 2){
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                ans = max(ans, a[i] & a[j]);
        cout << ans << '\n';
        return 0;
    }
    for (int i = 1; i <= n; i++){
        dp[i][1] = mx[i];
        dp[i][i] = all[i];
    }
    for (int i = 3; i <= n; i++)
        for (int j = 2; j < i; j++) dp[i][j] = max(dp[i - 1][j - 1] & a[i], dp[i - 1][j]);
    for (int i = m; i <= n; i++) ans = max(ans, dp[i][m]);
    cout << ans << '\n';
    return 0;
}
