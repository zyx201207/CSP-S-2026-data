#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
bitset<MAXN> f[32];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        for (int lg = 0; lg < 30; lg++)
            if (a & (1 << lg))
                f[lg][i] = a & (1 << lg);
    }
    int ans = 0;
    bitset<MAXN> s;
    s.set();
    for (int lg = 29; lg >= 0; lg--)
    {
        if ((s & f[lg]).count() >= m)
        {
            ans |= (1 << lg);
            s &= f[lg];
        }
    }
    cout << ans;
    return 0;
}