#include <bits/stdc++.h>
using namespace std;

pair<int, char> a[200100], b[200100];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second, b[n - i + 1] = a[i];
    long long ans = 0ll;
    int l = 1, r = 1;
    while (l <= n && r <= n) {
        if (a[l].second != b[r].second) {
            if (a[l].first < b[r].first)
                ans += a[l].first, b[r].first -= a[l].first, l++;
            else
                ans += b[r].first, a[l].first -= b[r].first, r++, l += (a[l].first == 0);
        } else {
            if (a[l].first < b[r].first)
                b[r].first -= a[l].first, l++;
            else
                a[l].first -= b[r].first, r++, l += (a[l].first == 0);
        }
    }
    cout << ans / 2;
}
