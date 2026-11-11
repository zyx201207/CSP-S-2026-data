#include <iostream>
#include <algorithm>
bool compare(long long x, long long y) {
    return x > y;
}
using namespace std;
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, compare);
    long long ans = a[0];
    for (long long i = 1; i < m; i++) ans &= a[i];
    cout << ans;
}
