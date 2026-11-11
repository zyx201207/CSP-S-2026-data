#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[500005];
int s[500005];
int n, m;

int pos(int j, int i)
{
    int lng = j - i + 1;
    return 1ll * a[j] * lng - (s[j] - s[i - 1]);
}

int chk(int x)
{
    int l = 1;
    int r = x;
    int ans = 0;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(pos(x, mid) <= m)
        {
            ans = x - mid + 1;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, chk(i));
    }
    cout << ans << "\n";
    return 0;
}