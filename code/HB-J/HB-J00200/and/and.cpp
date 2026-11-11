#include <bits/stdc++.h>
const int maxn = 2e5 + 10;
using namespace std;
long long n, m, a[maxn], f[maxn];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
  //  f[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = a[i];
    }
    sort (f + 1, f + n + 1);
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--){
            f[j] = max(f[j], f[j - 1] & a[i]);
  //          cout << f[j] <<' ';
        }
    }
    cout << f[m];
    return 0;
}
