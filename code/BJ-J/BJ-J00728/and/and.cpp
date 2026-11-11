#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
int n,m,a[maxn];
ll sum[maxn];
bool vis[maxn];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    ll maxv = 0;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    ll ans = a[n];
    sum[1] = a[1];
    for(int i = 2;i <= n;++i)
    {
        sum[i] = sum[i - 1] & a[i];
    }
    ll num = 1;
    for(int i = n - 1;i >= 1;i--)
    {
        if(vis[i]) continue;
        ll maxv = ans & a[i];
        ll pos = i;
        for(int j = 1;j <= i - 1;++j)
        {
            if(ans & a[j] > maxv && !vis[j])
            {
                pos = j;
                maxv = ans & a[j];

            }
        }
        ans = ans & a[pos];
        vis[pos] = true;
        num++;
        if(num == m) break;
    }
    cout << ans;
    return 0;
}
