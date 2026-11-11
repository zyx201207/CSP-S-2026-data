#include <iostream>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n, m;
ll a[N], b[N], maxn;
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            b[j] = a[i] & a[j];
            maxn = max(b[j], b[j - 1]);
        }
    }
    cout << maxn;
    return 0;
}
