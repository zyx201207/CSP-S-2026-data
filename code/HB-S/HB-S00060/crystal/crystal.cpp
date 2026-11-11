# include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N], s[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    long long m;
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    int ret = 1;
    for (int l = 1, r = 1; l <= n, r <= n; r++) {
        if (a[r] * (r - l + 1) - s[r] + s[l - 1] <= m) {
            ret = max(ret, r - l + 1);
        } else {
            l++;
        }
    }
    printf("%d", ret);
    return 0;
}
