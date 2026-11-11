#include <bits/stdc++.h>
using namespace std;
long long n , m , a[500010] , sa[500010];
bool check(long long mid)
{
    for(int i = 0;i <= n - mid;i++)
    {
        long long sum = sa[mid + i] - sa[i];
        sum = a[mid + i] * mid - sum;
        if(sum <= m) return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1 , a + n + 1);
    sa[0] = 0;
    for(int i = 1;i <= n;i++) sa[i] = sa[i - 1] + a[i];
    long long l = 1 , r = n , ans = -1e9;
    while(l <= r)
    {
        long long mid = (l + r) >> 1;
        if(check(mid))
        {
            ans = max(ans , mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}