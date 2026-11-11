#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5e5 + 10;
#define ll long long
ll a[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n; ll m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int p = 0, ans = 0; ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        while ((i - p) * a[i] - sum > m) sum -= a[p], p++;
        ans = max(ans, i - p);
    }
    cout << ans << endl;
    return 0;
}