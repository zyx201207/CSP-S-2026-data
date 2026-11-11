#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+5;
int n, ans = 1;
ll m, a[N], d, dif[N], s[N];
bool flagA = 1, flagB = 1;
map<ll, int> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        if (a[i] != i) flagA = 0;
        if (i == 2) d = a[2]-a[1];
        if (i>2 && a[i]-a[i-1]!=d) flagB = 0;
    }
    if (flagA)
    {
        ll mxsum = 1ll*n*(n-1)/2;
        if (m >= mxsum)
        {
            cout << n;
            return 0;
        }
        ll delta = sqrt(m*8+1);
        ll x = (delta-1)/2;
        cout << x+1;
        return 0;
    }
    if (flagB)
    {
        ll mxsum = (a[1]+a[n-1])*(n-1)/2;
        if (m >= mxsum)
        {
            cout << n;
            return 0;
        }
        if (m < d)
        {
            cout << 1;
            return 0;
        }
        ll p = d;
        for (int i = 1; i <= n; i++)
        {
            if (m >= p)
            {
                m -= p;
                ans++;
                p += d;
            }
            else break;
        }
        cout << ans;
        return 0;
    }
    sort(a+1, a+n+1);
    for (int i = 1; i < n; i++)
    {
        if (a[i+1] != a[i]) dif[i] = a[i+1]-a[i];
        else dif[i] = dif[i-1];
        s[i] = s[i-1]+dif[i];
    }
    for (int st = 1; st < n; st++)
    {
        ll tpm = m;
        int id = st, tpl = 0;
        while (id<n && tpm>s[id]-s[st-1])
        {
            tpl++;
            tpm -= s[id]-s[st-1];
            id++;
        }
        ans = max(ans, tpl+mp[a[id]]);
    }
    cout << ans;
    return 0;
}
