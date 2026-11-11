# include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
long long a[N], s[N];
int c;
void solve() {
    int n;
    long long d;
    scanf("%d%lld", &n, &d);
    long long tot = n * (n - 1) / 2;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    if (c == 11 || c == 12) {
        int D = (a[2] - a[1]);
        if (D * 2 >= d) {
            puts("0");
        } else {
            printf("%d\n", n - 2);
        }
        return;
    }
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int T;
    scanf("%d%d", &c, &T);
    while (T--) {
        solve();
    }
    return 0;
}
