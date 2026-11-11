#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int n;
ll m;
ll a[500001];
ll sum[500001];
ll need(int l, int r)
{
    return (r-l+1) * a[r] - (sum[r] - sum[l-1]);
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i-1] + a[i];

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = i, pos = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (need(mid, i) <= m)
            {
                r = mid - 1;
                pos = mid;
            }
            else l = mid + 1;
        }
        // cout << pos << " " << i << endl;
        ans = max(ans, i - pos + 1);
    }
    cout << ans << endl;
    return 0;
}