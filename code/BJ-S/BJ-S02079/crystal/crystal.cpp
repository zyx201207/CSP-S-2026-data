#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
long long n, m, a[N], sum[N], ans;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++)
        sum[i] = sum[i - 1] + a[i];
    for(int i = 1; i <= n; i ++)
    {
        int l = 1, r = i, cnt = i;
        while(l <= r)
        {
            int mid = (r + l) / 2;
            if(a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m)
            {
                cnt = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        ans = max(ans, i - cnt + 1ll);
    }
    cout << ans << endl;
    return 0;
}
