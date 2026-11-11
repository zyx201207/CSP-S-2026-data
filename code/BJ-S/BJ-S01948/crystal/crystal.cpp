#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[1000005],sa[1000005],dp[100005];
int maxn;
int b[1000005];
int n,m;

bool check(int w)
{
    memset(b,0,sizeof(b));
    for (int i = 1; i <= n; i++)
    {
        b[i] = a[i];
    }
    sort(b + 1,b + n + 1);
    for (int j = w; j <= n; j++)
    {
        int ans = 0;
        for (int k = j; k >= j - w + 1; k--)
        {
            ans += b[j] - b[k];
        }
        if (ans <= m)
        {
            return 1;
        }
    }
    return 0;
}

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sa[i] = sa[i - 1] + a[i];
        maxn = max(maxn,a[i]);
    }

    int l = 1,r = n;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << l;
    return 0;
}
