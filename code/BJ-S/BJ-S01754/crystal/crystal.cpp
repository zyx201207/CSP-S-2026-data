#include <bits/stdc++.h>
using namespace std;

int n;
long long a[500005], sum[500005], m;

bool check(int x) {
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
    bool flag = false;
    for (int i = x; i <= n; ++i) {
        long long k, l = i - x, r = i - 1;
        k = a[i] * (r - l + 1) - (sum[r] - sum[l - 1]);
        if (k <= m) flag = true;
    }
    return flag;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)  cin >> a[i];
    sort(a + 1, a + n + 1);
    int L = 1, R = n;
    while (L < R) {
        int mid = (L + R) / 2;
        if (check(mid)) L = mid + 1;
        else R = mid;
    }
    cout << L << endl;
    return 0;
}
