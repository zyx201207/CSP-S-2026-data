#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],sum[500005],ans;
bool flag = true;
bool check(int aim)
{
    for (int ll = 1;ll + aim-1 <= n;ll++)
    {
        int rr = ll+aim-1;
        int s = aim*a[rr]-(sum[rr]-sum[ll-1ll]);
        if (s <= m) return true;
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if (a[i] != i) flag = false;
    }
    if (flag)
    {
        int num2 = 0,sum2=0;
        while (sum2 <= m)
        {
            sum2 += num2;
            num2++;
        }
        num2--;
        cout << min(num2,n);
    }
    else
    {
        sort(a+1,a+n+1);
        for (int i = 1;i <= n;i++)
        {
            sum[i] = sum[i-1]+a[i];
        }
        int l = 1,r = n;
        while (l <= r)
        {
            int mid = (l+r)/2;
            if (check(mid))
            {
                ans = mid;
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        cout << ans;
    }
    return 0;
}
