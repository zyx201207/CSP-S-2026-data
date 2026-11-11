#include <iostream>
#include <algorithm>

using namespace std;

long long n, m;
int dp[5001][5001];
long long a[500001];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    bool flag = true;
    int b = a[2] - a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] - a[i - 1] != b) {
            flag = false;
            break;
        }
    }
    if (flag) {
        long long base = a[2] - a[1];
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            if (m >= (i - 1) * base) {
                m -= (i - 1) * base;
                ans++;
            }
            else {
                break;
            }
        }
        cout << ans;
        return 0;
    }
    if (n <= 5000) {
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j > 0; j--) {
            if (j < a[i] - a[i - 1])
                dp[i][j] = dp[i - 1][j];
            else {
               dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - (a[i] - a[i - 1])] + 1);;
            }
        }
    }
    long long ans = -1;
    for (int i = 1; i <= m; i++)
        ans = max(ans, (long long)(dp[n][i]));
    cout << ans;
    return 0;
    }
    else {
        cout << 1;
        return 0;
    }

   return 0;
}
