#include<bits/stdc++.h>
using namespace std;
int a[200010], f[2010][2010];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    if(m == n)
    {
        int res = 2147483647;
        for(int i = 1; i <= n; i++)res &= a[i];
        cout << res << "\n";
        return 0;
    }
    else if(m == 1)
    {
        int maxn = 0;
        for(int i = 1; i <= n; i++)
            maxn = max(maxn, a[i]);
        cout << maxn << "\n";
        return 0;
    }
    for(int i = 0; i <= n; i++)f[i][0] = 2147483647;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] & a[i]);
    int maxn = 0;
    for(int i = 1; i <= n; i++)
        maxn = max(maxn, f[i][m]);
    cout << maxn << "\n";
    return 0;
}
