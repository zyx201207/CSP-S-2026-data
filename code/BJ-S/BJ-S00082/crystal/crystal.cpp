#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],c[500010],suf[500010],sum[500010],ans;
bool check(int x)
{
    for(int i = x - 1,j = 0;i < n;i++,j++) if(sum[i] - sum[j] - suf[i + 1] * x <= m) return true;
    return false;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + 1 + n);
    for(int i = n - 1;i;i--) suf[i] = suf[i + 1] + a[i + 1] - a[i];
    for(int i = 1;i < n;i++) sum[i] = sum[i - 1] + suf[i];
    int l = 1,r = n;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(check(mid)) ans = mid,l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
