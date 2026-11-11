#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace _ {

    const int N = 5e5+10;

    int n, m;

    int a[N], pre[N];

    int res = 0;

    signed main() {

        freopen("crystal.in","r",stdin);
        freopen("crystal.out","w",stdout);

        cin >> n >> m;
        for (int i = 1;i<= n;i++) {
            cin >> a[i];
        }

        sort(a+1, a+n+1);
        for (int i = 1;i<= n;i++) {
            pre[i] = pre[i-1] + a[i];
        }

        for (int i = 1;i<= n;i++) {

            int l = 1, r = i, ans = i;
            while (l <= r) {

                int mid = (l + r) >> 1;

                if (a[i] * (i - mid + 1) - (pre[i] - pre[mid - 1]) <= m) {

                    ans = mid, r = mid - 1;

                } else l = mid + 1;

            }
    
            res = max(res, i - ans + 1);

        }

        cout << res << endl;


        return 0;
    }

}

signed main() {
    return _::main();
}