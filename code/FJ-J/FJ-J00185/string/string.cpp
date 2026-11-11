#include <iostream>
#define LL long long
using namespace std;
const int maxn = 2e5 + 10;
long long a[maxn];
char c[maxn];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    LL n;
    cin >> n;
    for (LL i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }
    LL l = 1, r = n;
    long long ans = 0;
    while (l < r) {
        if (a[l] > a[r]) {
            if (c[l] != c[r]) {
                ans += a[r];
            }
            a[l] -= a[r];
            r--;
        }
        else if (a[l] == a[r]) {
            if (c[l] != c[r]) {
                ans += a[l];
            }
            l++;
            r--;
        }
        else {
            if (c[l] != c[r]) {
                ans += a[l];
            }
            a[r] -= a[l];
            l++;
        }
    }
    cout << ans << endl;
    return 0;
}