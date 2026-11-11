
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N] , dp[N];

int main()
{
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    int n , m  , maxn = 0;
    cin >> n >> m;

    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = m;j >= 1;j--)
        {
            if (dp[j] == 0)
            {
                dp[j] = a[i];
            }
            else
            {
                dp[j] = max(dp[j] , dp[j - 1] & a[i]);
                maxn = max(maxn , dp[j]);
            }
        }
    }
    cout << maxn << endl;
    return 0;
}
