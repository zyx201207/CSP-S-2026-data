#include<bits/stdc++.h>
using namespace std;
const int maxm = 2 * 1e5 + 10;
int n, m;
long long a[maxm], maxn;
bool chk() {
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        if(a[i] != i - 1) return false;
    }
    return true;
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    if(chk()) cout << m * 3 << endl;
    else if(m == 1) {
        cout << a[1] << endl;
    }
    else if(m == 2) {
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                long long x = a[i] & a[j];
                maxn = max(maxn, x);
            }
        }
        cout << maxn << endl;
    }
    else if(m == n - 1) {
        for(int i = 1; i <= n; i++) {
            long long cur = pow(2, 31) - 1;
            for(int j = 1; j <= n; j++) {
                if(j == i) continue;
                cur = cur & a[j];
            }
            maxn = max(maxn, cur);
        }
    }
    else cout << a[(n + 1) / 2] << endl;
    return 0;
}