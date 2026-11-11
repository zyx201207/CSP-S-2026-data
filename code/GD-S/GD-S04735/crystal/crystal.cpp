#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 5;

ll a[N], s[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + a[i];
    }
    int l = 0;
    int ans = 1;
    for (int i = 1; i <= n; ++i) { // target
        while(a[i] * (i - l) -(s[i] - s[l]) > m) {
            ++l;
        }
        ans = max(ans, i - l);
    }
    cout << ans;

    return 0;
}

