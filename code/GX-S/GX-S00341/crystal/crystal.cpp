#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int n, ans = 1;
long long m, a[500001], presum[500001];

int main ()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        presum[i] = presum[i - 1] + a[i];
    for (int i = 2; i <= n; i++)
    {
        int L = 1, R = i;
        int j = i - 1;
        while (L < R)
        {
            j = (L + R) / 2;
            int len = i - j;
            long long res = len * a[i] - presum[i - 1] + presum[j - 1];
            if (m - res > 0)
            {
                ans = max(ans, i - j + 1);
                R = j;
            }
            else if (m - res < 0)
                L = j + 1;
            else
            {
                ans = max(ans, i - j + 1);
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
