// 100 pts

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n;
    i64 m;
    cin >> n >> m;

    vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    
    vector<i64> sum(n + 1);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i];

    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = i;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (a[i] * (i - mid + 1) - sum[i] + sum[mid - 1] > m)
                l = mid + 1;
            else
                r = mid;
        }
        ans = max(ans, i - l + 1);
    }

    cout << ans << endl;
    return 0;
}