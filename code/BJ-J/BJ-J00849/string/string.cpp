#include <bits/stdc++.h>
using namespace std;
int t;
struct node {
    int n;
    char c;
}a[200010];
long long ans = 0;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> a[i].n >> a[i].c;
    }
    for (int l = 1, r = t; l <= r; ) {
        if (a[l].c != a[r].c) {
            long long num = min(a[l].n, a[r].n);
            a[l].n -= num;
            a[r].n -= num;
            ans += num;
        } else {
            long long num = min(a[l].n, a[r].n);
            a[l].n -= num;
            a[r].n -= num;
        }
        if (a[l].n == 0) {
            l++;
        }
        if (a[r].n == 0) {
            r--;
        }
    }
    cout << ans << endl;
    return 0;
}
