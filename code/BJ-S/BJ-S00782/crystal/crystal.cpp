#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[500005];

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int l = 0, r = 1, cs = 0, mxp = -1;
    for (int i = 1;i < n;i++, r++) {
        cs += (r - l) * (a[i] - a[i-1]);
        while (cs > m && l < r) {
                cs -= (a[r] - a[l]);
                l++;
        }
        mxp = max(mxp, r-l+1);
    }
    cout << mxp << endl;
    return 0;
}
/*
5 4
-1 -1 -1 -1 0
*/
