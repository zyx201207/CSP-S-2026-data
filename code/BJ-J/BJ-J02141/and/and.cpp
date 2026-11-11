#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200005], t = 1;
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (long long i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    if (m == n) {
        for (long long i = 1; i <= n; ++i) {
            t = (t & a[i]);
        }
        return 0;
    }
    cout << a[n];
    if (m == 1) {
        cout << a[n];
        return 0;
    }
    if (m == 2) {
        int top = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if ((a[i] & a[j]) > top){
                    top = (a[i] & a[j]);
                }
            }
        }
        cout << top;
        return 0;
    }
    return 0;
}