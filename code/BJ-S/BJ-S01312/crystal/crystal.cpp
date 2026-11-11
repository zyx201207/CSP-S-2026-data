#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(signed argc, char* argv[]) {
    // freopen(argv[1], "r", stdin);
    // freopen(argv[2], "w", stdout);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m; scanf("%lld %lld", &n, &m);
    vector<int> a(n + 1);
    vector<int> sa(n + 1, 0);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    sort(a.begin() + 1, a.end());
    for(int i = 1; i <= n; i++) sa[i] = sa[i - 1] + a[i];
    auto check = [&](int x) {
        //cout << "checkmid " << x << ": ";
        for(int i = 1; i + x - 1 <= n; i++) {
            int sum = sa[i + x - 2] - sa[i - 1];
            int tar = a[i + x - 1] * (x - 1);

            //cout << i << ' ' << sum << ' ' << tar << endl;

            if(tar - sum <= m) {
           //         cout << "true\n";
           // cout << endl << tar << ' ' << sum << ' ' << tar - sum << ' ' << m << endl;
                return true;
            }
        }

         //           cout << "false\n";
        return false;
    };

    int l = 0, r = n;
    // int idx = 0;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        bool cmid = check(mid);
        // cout << l << ' ' << r << ' ' << mid << ' ' << cmid << endl;
        if(cmid) l = mid;
        else r = mid - 1;
    }
    // printf("%lld", check(l));
    printf("%lld", l);
}
