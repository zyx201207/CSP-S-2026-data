#include <bits/stdc++.h>
using namespace std;
long long a[10005], cnt = 0;
long long maxn = -1e9;
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    if(m == 2)
    {
        long long ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = i+1; j <= n; ++j)
            {
                ans = a[i] & a[j];
                maxn = max(maxn, ans);
            }
        }
    }
    if(m == 1)
    {
        for(int i = 1; i <= n; ++i)
        {
            maxn = max(maxn, a[i]);
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            ans = a[i] & a[j] & a[j+1];
            maxn = max(maxn, ans);
        }
    }
    cout << maxn;
    return 0;
}
