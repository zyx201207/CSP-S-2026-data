#include <bits/stdc++.h>
using namespace std;
int a[10005], cnt = 0;
long long maxn = -1e9;
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i+1; j <= n; ++j)
        {
            ++cnt;
            if(cnt == m - 1)
            {
                break;
            }
            long long ans = a[i] & a[j] & a[j+1];
            maxn = max(maxn, ans);
        }
    }
    return 0;
}
