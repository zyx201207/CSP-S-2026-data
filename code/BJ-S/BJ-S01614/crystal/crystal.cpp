#include <iostream>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;
ll a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin >> n >> m;
    for (ll i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    ll sum = 0,ans = 0,cnt = 0;
    for (ll i = 1,j = 0;j < n;)
    {
        j++;
        sum += cnt*(a[j]-a[j-1]);
        cnt++;
        while (sum > m)
        {
            sum -= (a[j] - a[i]);
            cnt--;
            i++;
        }
        //cout << i << ' ' << j << ' ' << cnt << "\n";
        ans = max(ans,cnt);
    }
    cout << ans;
    return 0;
}
