#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
typedef long long ll;

int c, T, n;
ll d, a[N];
int check(int x, int l, int r) {
    int cnt = 0;
    ll now = d;
    for (int i = l + 1; i <= r; i++) {
        if (now - (a[i] - a[i - 1]) >= 0) now -= a[i] - a[i - 1];
        else {
            if (d < a[i] - a[i - 1]) return -1;
            else now = d - (a[i] - a[i - 1]), cnt++;
        }
    }
    return (cnt <= x);
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> c >> T;
    while (T--) {
        int ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) 
            for (int j = i + 1; j <= n; j++) {
                int l = 1, r = j - i, len = 0;
                bool flag = 1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    int tmp = check(mid, i, j);
                    if (tmp == 1) r = mid - 1, len = mid;
                    else if (tmp == 0) l = mid + 1;
                    else {flag = 0; break;}
                }
                if (len < j - i && flag) ans++;
            }
        cout << ans << '\n';
    }
    return 0;
}