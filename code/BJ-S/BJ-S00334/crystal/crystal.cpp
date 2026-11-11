#include <iostream>
using namespace std;
#define int long long

const int N = 5e5 + 5;
int a[N];

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; ++ i)
    {
        int cnt = 0, sum = 0;
        for (int j = 1; j <= n; ++ j)
        {
            if (a[j] > a[i]) continue;
            cnt += a[i] - a[j];
            if (cnt > m) break;
            sum += 1;
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}