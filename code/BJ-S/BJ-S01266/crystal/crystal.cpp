#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000000];
int f[1000000];
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        f[i]  = f[i - 1] + a[i];
    }
    int maxn = 0;
    for(int i = n; i >= 1; i--)
    {
        int l = 1, r = i;
        while(l < r)
        {
            int mid = (l + r) / 2;
            if(a[i] * (i - mid + 1) - (f[i] - f[mid - 1]) <= m)
            {
                r = mid;
            }
            else 
            {
                l = mid + 1;
            }
            //cout << l << " " << r  << endl;
        }
        maxn = max(maxn, i - r + 1);
    }
    cout << maxn;
    return 0;
}