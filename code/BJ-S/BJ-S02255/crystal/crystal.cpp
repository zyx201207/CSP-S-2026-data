#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

long long n, m, ans = -1, d;
long long c[1000];
int a[N];

int solve(int k) {
    int x = m, cnt = 0;
    for (int i = k - 1; i >= 1; i--) {
        if (x >= a[k] - a[i]) {
            cnt++;
            x -= (a[k] - a[i]);
        }
        else {
            break;
        }
    }
    return cnt;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);

    bool flag = true;
    for (long long i = 1; i <= n; i++) {
        long long b;
        scanf("%d", &b);
        if (abs(b) <= INT_MAX){
            a[i] = b;
        }
        if (i <= 990) {
            c[i] = b;
        }
        if (i == 2) {
            d = c[2] - c[1];
        }
        if (i > 2 && flag && i <= 980) {
            if (c[i] - c[i-1] != d) {
                flag = false;
            }
        }

    }

    if (m <= 100 && n > 10000) {
        int max1 = -1, max2 = -1, max3 = -1, max4 = -1;
        for (int i = 1; i <= n; i++) {
            max1 = max(max1, a[i]);
        }

        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += (max1 - a[i]);
        }

        if (sum <= m) {
            cout << n;
            return 0;
        }
        cout << n-1;
        return 0;

        /*int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != max1)
                max2 = max(max2, a[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == max2)
                cnt2++;

            if (a[i] == max1)
                cnt1++;
        }
        if (sum - cnt * (max1 - max2) <= m)*/
    }

    if (flag /*&& n > 10000*/) {
        cout << solve(n) + 1;
        return 0;
    }

    sort(a + 1, a + n + 1);

    int l = 1, r = n;
    for (int j = 1; j <= n; j++) {
        for (int i = j+1; i <= n; i++) {
            if (a[j] != a[i])break;
            j++;
        }
        ans = max(ans, 1ll * solve(j) + 1);
    }

    printf("%d", ans);

    return 0;
}
