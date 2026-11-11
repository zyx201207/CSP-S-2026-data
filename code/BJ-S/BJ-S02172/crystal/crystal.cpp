#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

long long a[500010], b[500010], dp[500010];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++)
    {
        b[i] = a[i + 1] - a[i];
        //cout << a[i] << " ";
    }
    //cout << endl;
    //int cur = 1;
    int maxn = -1;
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            dp[j] = dp[j - 1] + j * b[i];
            /*cout << dp[j] << " ";
            if (dp[j] > m)
            {
                cur = j - 1;
                cout << "!!!" << endl;
                break;
            }*/
            if (dp[j] <= m) maxn = max(maxn, j);
        }
        /*cur = i + 1;
        cout << endl;*/
    }
    cout << maxn + 1 << endl;
    return 0;
}
