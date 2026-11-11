#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pair<int, int>minn;
    minn.first = 1e9;
    int n, m;
    int a[500005] = {};
    int cnt[500005] = {};
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    cnt[1] = a[1];
    for (int i = 2 ; i <= n ; i++)
    {
        cnt[i] = cnt[i - 1] + a[n];
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = i ; j <= n ; j++)
        {
            if(a[j] - a[i] <= m && j - i >= ans)
            {
                ans = j - i;
            }
        }
    }
    cout << ans + 1;
    fcloseall();
    return 0;

}
