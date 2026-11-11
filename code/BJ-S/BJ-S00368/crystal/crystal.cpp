#include <bits/stdc++.h>
#define int long long
#define ll __int128
using namespace std;
const int maxn = 5e5 + 5;
int n, m, a[maxn];
ll s[maxn];

bool check(int mid) {
    for (int i = mid;i <= n;i++) {
        ll sum = s[i] - s[i - mid];
        if ((__int128)a[i] * mid - sum <= m) return 1;
    }
    return 0;
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1;i <= n;i++) s[i] = s[i-1] + a[i];
    int l = 2, r = n, ans = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}

/*

g++ crystal.cpp -o crystal -std=c++14 -Wall -O2 -Wextra
ulimit -s 102400
./crystal

__int128

5 8
-3 -1 2 2 7
*/
