#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
constexpr int N = 2000005;
int n;
ll d, x[N];
int l[N], r[N];
int l1[N], r1[N];
int pre[N], suf[N];
void work() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    int p = 1;
    for (int i = 1; i <= n; i++) {
        while (x[i] - x[p] > d)
            ++p;
        l[i] = p;
    }
    p = n;
    for (int i = n; i; i--) {
        while (x[p] - x[i] > d)
            --p;
        r[i] = p;
    }
    p = 1;
    for (int i = 1; i < n; i++) {
        while (r[p] <= i)
            ++p;
        l1[i] = p;
    }
    p = n;
    for (int i = n; i > 1; i--) {
        while (l[p] >= i)
            --p;
        r1[i] = p;
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = (l[i] < i && r[l[i]] == i ? pre[l[i]] + (l1[l[i]] - l[l[i]]) : 0);
    }
    for (int i = n; i; i--) {
        suf[i] = (r[i] > i && l[r[i]] == i ? suf[r[i]] + (r[r[i]] - r1[r[i]]) : 0);
    }
    ll res = 0;
    for (int i = 1; i < n; i++) {
        if (l[i] == i || r[i + 1] == i || x[i + 1] - x[i] > d)
            continue;
        ll cl = (l[i] == l[i + 1] ? pre[i + 1] : 0), cr = (r[i] == r[i + 1] ? suf[i] : 0);
        cl += min(l1[i + 1], i) - l[i + 1];
        cr += r[i] - max(r1[i], i + 1);
        // cerr << i << ',' << i + 1 << ":" << l[i] << ',' << l[i + 1] << ' ' << r[i] << ',' << r[i + 1] << ' ' << cl << ',' << cr << '\n';
        res += cl * cr;
    }
    cout << res << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--)
        work();
    return 0;
}