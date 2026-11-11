#include<bits/stdc++.h>
using namespace std;
const int N = 6e5 + 100;

long long ch, ch1, ans, l, r, cnt, mm, mx = INT_MIN;
long long n, m;
long long a[N];
bool f1, f2, f;

bool cmp(long long x, long long y) {
    return x < y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        if (a[i] != i) f1 = true;
        if (i >= 3) {
            if (ch != a[i] - a[i - 1]) f2 = true;
        }
        if (i >= 2) ch = a[i] - a[i - 1];
    }
    if (!f1) {
        for (int i = 1; i < n; i++) {
            m -= i;
            if (m >= 0) {
                ans++;
            }
            else break;
        }
        cout << ans + 1 << "\n";
        return 0;
    }
    if (!f2) {
        for (int i = 1; i < n; i++) {
            m -= i * ch;
            if (m >= 0) {
                ans++;
            }
            else break;
        }
        cout << ans + 1 << "\n";
        return 0;
    }
    //for (int i = 1; i <= n; i++) {
    //    cout << a[i] << "\n";
    //}
    l = 1, r = 1;
    ch = 0;
    //cout << n << " " << m << "\n";
    for (int i = 2; i <= n; i++) {
        ch = a[i] - a[i - 1];
        ch1 = 0;
        cnt = 0;
        f = 0;
        while ((mm <= m) && (r <= n)) {
            //cout << ((mm <= m) && (r <= n)) << " " << (mm <= m) << " " << (r <= n) << "\n";
            f = 1;
            r++;
            mm += (r - l) * max(0ll, (a[r] - a[r - 1]));
            cnt += ch;
            //cout << "处理: " << "i: " << i << " ch1: " << ch << " ch: " << ch << " l: " << l << " r: " << r << " mm: " << mm << " cnt: " << cnt << " 数量: " << (r - l) << "\n";
        }
        mx = max(mx, (r - l));
        mm -= cnt;
        l = i;
        ch1 = max(0ll, (a[r] - a[i - 1]));
        if (mm > m) mm -= ch1;
        //cout << "i: " << i << " ch1: " << ch1 << " ch: " << ch << " l: " << l << " r: " << r << " mm: " << mm << " cnt: " << cnt << " 数量: " << (r - l) << "\n";
        //cout << "\n";
    }
    cout << mx;
    return 0;
}
