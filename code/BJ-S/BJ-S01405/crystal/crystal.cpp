#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],sum[500005],ans;
bool check(int l,int r)
{
    return a[r] * (r - l + 1) - (sum[r] - sum[l - 1]) <= m;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 1;i <= n;i++)
        sum[i] = a[i] + sum[i - 1];
    for (int i = 1;i <= n;i++)
    {
        int l = 1,r = i,mid,as = n + 1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (check(mid,i))
            {
                as = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        ans = max(ans,i - as + 1);
    }
    cout << ans;
    return 0;
}
