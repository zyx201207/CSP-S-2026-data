# include <bits/stdc++.h>
using namespace std;
int n , m , cnt = 1;
long long a[200005] , p[200005][35] , sum[35] , ans;
int main () {
    freopen ("and.in" , "r" , stdin);
    freopen ("and.out" , "w" , stdout);
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    cin >> n >> m;
    for (int i = 1;i <= n;i ++) {
        long long b;
        cin >> a[i];
        b = a[i];
        string s = "";
        while (b != 0) {
            s += b % 2 + '0';
            b /= 2;
        }
        reverse (s.begin () , s.end ());
        while (int (s.size ()) < 31) {
            s = '0' + s;
        }
        for (int j = 0;j < 31;j ++) {
            p[i][j] = s[j] - '0';
            sum[j] += s[j] - '0';
        }
    }
    for (int i = 0;i < 31;i ++) {
        if (sum[i] >= m) {
            for (int j = 1;j <= n;j ++) {
                if (p[j][30] == -1) continue;
                if (p[j][i] == 0) {
                    for (int k = i;k < 31;k ++) {
                        if (p[j][k] == 1) {
                            sum[k] --;
                        }
                        p[j][k] = -1;
                    }
                }
            }
        }
    }
    int pos = INT_MAX;
    for (int i = 1;i <= n;i ++) {
        if (p[i][30] == -1) continue;
        ans = a[i];
        pos = min (pos , i);
    }
    for (int i = pos + 1;i <= n;i ++) {
        if (p[i][30] == -1) continue;
        ans &= a[i];
        cnt ++;
        if (cnt == m) break;
    }
    cout << ans;
    return 0;
}
