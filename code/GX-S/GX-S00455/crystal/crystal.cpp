#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n, asn = 0;
ll m, a[501314], s[501314];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >>a[i];
    sort(a + 1, a + 1 + n);
    s[0] = 0 * 1ll;
    for(int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + a[i];
    for(int i = 1; i <= n; ++i)
    {
        int l = 1, r = i;
        while(l <= r)
        {
            int mid = (l + r) >>1;
            ll res = 0, tot = 0;
            res = s[i] - s[mid - 1];
            tot = a[i] * 1ll * (ll)(i - mid + 1ll);
            if(tot - res <= m)
            {
                asn = max(asn, i - mid + 1);
                r = mid - 1;
            }
            else l = mid + 1;
        }
    }
    cout << asn << endl;
    return 0;
}

