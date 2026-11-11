# include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N];
char c[N];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        cin >> c[i];
    }
    int l = 1, r = n;
    long long ret = 0;
    while (l <= r) {
        if (c[l] == c[r]) {
            if (a[l] > a[r]) {
                a[l] -= a[r];
                r--;
            } else if (a[l] == a[r]) {
                l++, r--;
            } else {
                a[r] -= a[l];
                l++;
            }
        } else {
            ret += min(a[l], a[r]);
            if (a[l] == a[r]) {
                l++, r--;
            } else if (a[l] < a[r]) {
                a[r] -= a[l];
                l++;
            } else {
                a[l] -= a[r];
                r--;
            }
        }
    }
    printf("%lld", ret);
    return 0;
}
