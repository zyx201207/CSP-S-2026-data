#include <bits/stdc++.h>
using namespace std;

const int N = 500010;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n;
    long long m;
    long long a[N];

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    int ans = -1;
    long long num = 0;
    int l = 1, r = 0;
    while (r <= n) {
        while (r <= n && num <= m) {
            r++;
            if(r > 1)
                num += (a[r] - a[r - 1]) * (r - l);
            if (num <= m)
                ans = max(ans, r - l + 1);
        }
        while (l <= r + 1 && l <= n && num > m) {
            num -= a[r] - a[l];
            l++;
        }
    }

    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
