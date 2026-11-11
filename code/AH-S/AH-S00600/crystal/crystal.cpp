#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long a[N];
unsigned long long b[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n;
    long long m;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (long long i = 2; i <= n; i++) {
        b[i] = a[i] - a[1];
    }
    long long l = 1, r = 1;
    unsigned long long sum = 0;
    long long ans = 0;
    while (r < n) {
        r++;
        sum += (b[r] - b[r - 1]) * (r - l);
        while (sum > m) {
            sum -= b[r] - b[l];
            l++;
        }
        ans = max (ans, r - l + 1);
    }
    cout << ans;
    return 0;
}
