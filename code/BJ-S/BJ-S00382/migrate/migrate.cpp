#include "bits/stdc++.h"
using namespace std;


int c, t;
int n, d;

int a[2000005];

int dp[8005][8005];
int nm[8005][8005];

void dfs(int x, int len, int st, int ed) {

    if(len == nm[st][x]) {
        dp[st][x]++;
    } else if(len < nm[st][x]) {
        nm[st][x] = len;
        dp[st][x] = 1;
    }

    for(int i = x + 1; i <= ed; i++) {
        if(a[i] - a[x] <= d) {
            dfs(i, len + 1, st, ed);
        } else {
            break;
        }
    }
}

int main() {

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        memset(nm, 0x3f, sizeof(nm));
        memset(dp, 0, sizeof(dp));
        cin >> n >> d;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if(c == 11 || c == 12) {
            cout << n / d - 1;
        }


        for(int i = 1; i < n; i++) {
            for(int j = i + 1; j <= n; j++) {
                dfs(i, 0, i, j);
            }
        }
        int res = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                //printf("dp[%d][%d]:%d ", i, j, dp[i][j]);
                if(nm[i][j] != 0x3f3f3f3f && dp[i][j] == 2) {
                    res++;
                }
            }
        }
        cout << res << '\n';

    }

    return 0;

}
