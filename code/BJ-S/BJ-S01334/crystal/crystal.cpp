#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5+10;
long long n, m;
long long a[N];
long long ansmax;
int main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ansmax = 0;
    sort(a + 1, a + n + 1);
    for (long long i = n; i >= 1; i--) {
        long long t = m;
        long long ans = 1;
        for (long long j = i - 1; j >= 1; j--) {
            if (a[i] - a[j] <= t) {
                t = t - (a[i] - a[j]);
                ans++;
            }else{
                break;
            }
        }
        ansmax = max(ansmax, ans);
    }
    cout << ansmax;
    return 0;
}