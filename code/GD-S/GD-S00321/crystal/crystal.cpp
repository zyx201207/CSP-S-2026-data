#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 10;
int n,k,ans,a[maxn],sum[maxn];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++)sum[i] = sum[i - 1] + a[i];
    for(int i = 1;i <= n;i++)
    {
        int l = 1,r = i - 1,res = i;
        while(l <= r)
        {
            int mid = l + r >> 1;
            if(a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) > k)l = mid + 1;
            else r = mid - 1,res = mid;
        }
        ans = max(ans,i - res + 1);
    }
    cout << ans;
    return 0;
}
/*
100
黄？
*/