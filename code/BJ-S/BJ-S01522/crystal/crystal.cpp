#include <bits/stdc++.h>
#define ch(opt, tar, ...) tar = opt({tar, __VA_ARGS__})
#define isz(x) (int((x).size()))
#define inlfc __attribute__((always_inline)) inline
using namespace std;
typedef long long ll;
typedef __int128_t i128;
typedef pair<int, int> pii;


int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 1;
    ll m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    vector<i128> p(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i ++) p[i] = p[i - 1] + a[i];
    for (int i = 1, j = 0; i <= n; i ++) {
        while (j < i && i128(a[i]) * (i - j) - p[i] + p[j] > m) j ++;
        ch(max, ans, i - j);
    }
    cout << ans;
    return 0;
}
