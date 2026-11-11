#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll ans, l;
int a[200005];
ll sum[200005], rsum[200005];
char c[200005];

int main () {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> c[i];
        l += a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = n; i >= 1; --i) {
        rsum[i] = rsum[i + 1] + a[i];
    }
    ll lcnt = a[1], rcnt = 0;
    int lid = 1, rid = n + 1;
    while (lcnt < l / 2 || rcnt < l / 2) {
        if (lcnt == rcnt && sum[lid + 1] <= l / 2) {
            lid++;
            lcnt = sum[lid];
        }
        if (lcnt > rcnt) {
            while (rsum[rid - 1] <= lcnt) {
                rid--;
                if (c[lid] != c[rid]) {
                    ans += rsum[rid] - rcnt;
                }
                rcnt = rsum[rid];
            }
            if (lcnt > rcnt) {
                if (c[rid - 1] != c[lid]) {
                    ans += lcnt - rcnt;
                }
                rcnt = lcnt;
            }
        }
        if (lcnt + a[lid + 1] > l / 2) {
            lcnt = l / 2;
            lid++;
        }
    }
    cout << ans;
    return 0;
}
