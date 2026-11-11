#include<bits/stdc++.h>
using namespace std;

int n, m, a[500005], ans, sum[500005];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    if (n > 5000) {
        for (int i = 2; i <= n; i++) {
            int cnt = a[i] * i - sum[i];
            for (int j = 0; j <= i; j++) {
            if (cnt - a[i] * j + sum[j] <= m)
                ans = max(i - j, ans);
            else
                break;
            }
        }
    }
    else {
        for (int i = 2; i <= n; i++) {
            int cnt = a[i] * i - sum[i];
            if (cnt <= m)
                ans = i;
            else
                break;
        }
    }
    printf("%d", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
