#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2E5 + 5;
int a[N];
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    int ans = a[1];
    for (int i = 2; i <= m; i++)
        ans &= a[i];
    cout << ans;
    return 0;
}
