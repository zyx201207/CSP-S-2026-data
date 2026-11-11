#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
bool f[35][N];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if ((1<<i) & a[j]) f[i][j] = 1;
            else f[i][j] = 0;
            //cout << f[i][j] << ' ';
        }
        //cout << '\n';
        for (int j = 1; j <= n; j++) {
            if (f[i][j] & f[i+1][j]) f[i][j] = 1, cnt++;
            else f[i][j] = 0;
        }
        //cout << cnt;
        if (cnt >= m) ans += (1<<i);
        else if (i) {
            if (!ans) memset(f[i], 1, sizeof f[i]);
            else memcpy(f[i], f[i+1], sizeof f[i]);
        }
    }
    cout << ans;
    return 0;
}
/*
4 2
3 15 12 12
g++ -o o.exe travel.cpp
zen me hai you yuan ti wo yao fa luo gu
9:53
*/
