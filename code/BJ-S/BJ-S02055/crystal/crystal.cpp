#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 10;
int n, m;
int a[N];
int main()
{
    int ans = 0;
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    a[0] = 0;
    bool isdengcha = true;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (i >= 3) {
            if ((a[i] - a[i - 1]) != (a[i - 1] - a[i - 2])) {
                isdengcha = false;
            }
        }
    }
    sort(a + 1, a + n + 1);
    if (isdengcha == true) {
        int cha = a[2] - a[1];
        for (int i = 1; i >= -1; i ++) {
            if (m - cha * i < 0) {
                cout << min(ans + 1, n);
                return 0;
            }
            m -= cha * i;
            ans ++;
        }
    }
    else {
        int midnum = a[n / 2 + 1];
        for (int i = n; i >= 1; i --) {
            if (a[i] == midnum) {
                ans ++;
            }
            if (a[i] > midnum) {
                continue;
            }
            if (a[i] < midnum) {
                if (m - (midnum - a[i]) >= 0) {
                    ans ++;
                    m -= (midnum - a[i]);
                }
                else {
                    cout << ans;
                    return 0;
                }
            }
        }
        if (m > 0) {
            for (int i = midnum; i <= n; i ++) {
                if (a[i] == midnum) {
                    continue;
                }
                if (a[i] > midnum) {
                    if (m - (a[i] - midnum) >= 0) {
                        ans ++;
                        m -= (a[i] - midnum);
                    }
                    else {
                        cout << ans;
                        return 0;
                    }
                }
                if (a[i] < midnum) {
                    continue;
                }
            }
        }
        cout << ans;
    }
    return 0;
}