#include <bits/stdc++.h>
using namespace std;

const int N = int(5e5) + 10;

long long a[N], sum[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int res = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (a[i] * (i - j + 1) - (sum[i] - sum[j - 1]) > m) j++;
        res = max(res, i - j + 1);
    }
    cout << res;
    
    return 0;
}