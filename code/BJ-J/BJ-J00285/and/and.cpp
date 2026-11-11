#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n, m;
int a[N];
bool cmp(int x, int y) {
    int nx = __builtin_popcount(x), ny = __builtin_popcount(y);
    if (nx != ny) return nx > ny;
    else return x > y;
} 
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    int cnt = a[1];
    for (int i = 2; i <= m; i++) {
        cnt &= a[i];
    }
    cout << cnt;
    return 0;
}