#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 200010;

int n;
int a[MAXN];
char c[MAXN];

signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];

    int ans = 0;
    int i = 1, j = n;
    int rest_j = a[n];
    while (i < j) {
        int al = a[i];
        char cl = c[i];
        while (al > 0) {
            if (rest_j > al) {
                if (c[j] != cl) ans += al;
                rest_j -= al;
                break;
            }
            else {
                if (c[j] != cl) ans += rest_j;
                al -= rest_j;
                -- j;
                rest_j = a[j];
            }
        }
        ++ i;
    }
    cout << ans << '\n';
    return 0;
}
