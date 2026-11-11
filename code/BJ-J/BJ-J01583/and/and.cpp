#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int n, m, a[N], ans;
bool f1 = true, f2 = true;

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    //cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    //for (int i = 65435; i <= n; i++) cout << a[i] << ' ';
    //cout << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 31; j++) {
            if (a[i] != 1 << j) {
                f1 == false;
                break;
            }
        }
        if (a[i] != i - 1) f2 = false;
        if (f1 == false && f2 == false) break;
    }
    //cout << f1 << ' ' << f2 << '\n';
    if (f2 == true) {
        printf("%d", n - m);
        return 0;
    }
    if (f1 == true) {
        printf("0");
        return 0;
    }
    sort(a + 1, a + 1 + n, greater<int>());
    ans = a[1];
    for (int i = 2; i <= m; i++) {
        ans &= a[i];
    }
    printf("%d", ans);
    return 0;
}

// Trick or Treat!

