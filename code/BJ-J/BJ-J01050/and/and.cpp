#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+8, M = 2e5+8;
int n, m, a[N], dp[M];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> a[i];
    sort(a+1, a+n+1);
    if (n*m <= 100000000)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[m] = max(dp[m], a[i]);
            for (int j = 0; j <= m; j++)
            {
                if (j!=m)dp[j] = max(dp[j], dp[j+1]&a[i]);
            }
        }
        cout << dp[0] << endl;
    }
    else
    {
        bool flagA = 1, flagB = 1;
        for (int i = 1; i <= n; i++)
        {
            if (a[i]!=i-1)flagB = 0;
            if (!(abs((log2(a[i]+1))-(int)(log2(a[i]+1)))<=1e-5))flagA = 0;
        }
        if (n==m)
        {
            int cnt = a[1];
            for (int i = 2; i <= n; i++)cnt &= a[i];
            cout << cnt << endl;
        }
        else if (m==n-1)
        {
            int cnt = a[2];
            for (int i = 3; i <= n; i++)cnt &= a[i];
            cout << cnt << endl;
        }
        else if (flagB&&abs((log2(n))-(int)(log2(n)))<=1e-5)
        {
            int x = (int)ceil(log2(m));
            cout << n-(1<<x) << endl;
        }
        else if (flagA)
        {
            cout << a[n-m+1] << endl;
        }
        else cout << 3 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}