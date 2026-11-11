#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,maxn = 1;
int a[500010];

signed main ()
{
    freopen ("crystal.in","r",stdin);
    freopen ("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort (a + 1,a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        int cnt = 1,k = m;
        for (int j = i - 1; j >= 1; j--)
        {
            k -= a[i] - a[j];
            if (k < 0) break;
            cnt++;
        }
        maxn = max (maxn,cnt);
    }
    cout << maxn;
    return 0;
}