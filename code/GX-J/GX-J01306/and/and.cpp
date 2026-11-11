#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e+8;
int n, m, a[MaxN];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    cout << a[n];
    return 0;
}
