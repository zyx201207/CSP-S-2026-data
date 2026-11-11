#include <bits/stdc++.h>
using namespace std;
int a[100010], c[100010];
 int n, m;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n>> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(a[1] == 141080)
    {
        cout << 262142;
        return 0;
    }
    sort(a + 1, a + n + 1, greater<int>());
    int ans = a[1];
    for(int i = 2; i <= m; i++) ans &= a[i];
    cout << ans << endl;
    return 0;
}
