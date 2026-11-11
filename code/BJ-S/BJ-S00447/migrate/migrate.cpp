#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define int long long

int c, t, n, d, a[5005], b[5005];

bool check(int l, int r) {
    int cnt = 0, res = 0, lst = 0;
    for (int i = l; i <= r; i++) {
        int j = i + 1;
        if (i == lst) {
            //cout << l << " " << r << " " << cnt  << endl;
            //for (int i = 1; i <= cnt; i++)
                //cout << b[i] << " ";
        }
        if (a[i + 1] - a[i] > d && i < r || i == lst)
            return 0;
        while (a[j] - a[i] <= d && j <= r)
            j++;
        j--;
        b[++cnt] = j;
        lst = i;
        if (j == r) {
            //cout << l << " " << r << " " << cnt  << endl;
            //for (int i = 1; i <= cnt; i++)
                //cout << b[i] << " ";
            //cout << endl;
            break;
        }
        i = j - 1;
    }
    //if (l == 1 && r == 4) {
        //cout << l << " " << r << " " << cnt  << endl;
        //for (int i = 1; i <= cnt; i++)
            //cout << b[i] << " ";
        //cout << endl;
    //}
    for (int i = 2; i <= cnt; i++) {
        int j = b[i - 1] - 1;
        while (a[b[i]] - a[j] <= d && j >= 1) {
            res++;
            j--;
        }
    }
    if (res == 1) {
        //cout << cnt << endl;
        //for (int i = 1; i <= cnt; i++)
            //cout << b[i] << " ";
    }
    return res == 1;
}

void solve() {
    int ans = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (check(i, j)) {
                ans++;
                //cout << i << " " << j << endl;
            }
    cout << ans << endl;
}

void solve1() {
    int ans = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int l = 1; l <= n; l++) {
        int p1 = upper_bound(a + 1, a + n + 1, a[l] + d) - a - 1, p2 = upper_bound(a + 1, a + n + 1, a[p1] + d) - a - 1;
        if (a[p2] - a[p1 - 1] <= d)
            continue;
        while (a[p2] - a[p1 - 1] > d) {
            ans++;
            p2--;
        }
    }
    cout << ans << endl;
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    if (c <= 10) {
        while (t--)
            solve();
        return 0;
    }
    while (t--)
        solve1();
    return 0;
}
