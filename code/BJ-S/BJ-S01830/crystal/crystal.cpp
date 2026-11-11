#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n;
ll m;
ll a[500010];
ll d[500010];
ll ans;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    int ans = 0;
    ll sum = 0;
    int l = 1;
    for(int r = 1; r <= n; r++)
    {
        sum += (a[r] - a[r - 1]) * (r - l);

        while(sum > m)
        {
            sum -= a[r] - a[l];
            l += 1;
        }
        
        ans = max(ans, r - l + 1);
    }

    cout << ans;

    return 0;
}