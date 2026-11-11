//#define int long long
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int n, m, C, T, d;
long long a[N], f[N], s[N];
long long l(long long x, long long y)
{
    return abs(a[x] - a[y]);
}
void fp(long long x, long long y)
{
    long long mn = 2e9;
    for (long long i = 1; i <= d; i++)
    {
        if ( x > y )
            mn = min(mn, f[x+i]);
        else
            mn = min(mn, f[x-i]);
    }
    f[x] = mn;
}
bool fx2l(long long x, long long center)
{
    long long mn = 2e9, cnt = 0;
    for (long long i = 1; i <= d; i++)
    {
        if ( f[x-i] == center ) continue;
        if ( x - i > center )
        {
            if ( f[x-i] < mn )
            {
                cnt = 1;
                mn = f[x-i];
            }
            else if ( f[x-1] == mn )
            {
                cnt++;
            }
        }
        else break;
    }
    return cnt == 2;
}

signed main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin >> C >> T;
    while (T--)
    {
        long long ans = 0;
        cin >> n >> d;
        for (long long i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        for (long long i = 1; i <= n; i++)
        {
            for (long long j = i; j <= 1; j++)
            {
                fp(i, j);
            }
        }
        for (long long i = 1; i <= n; i++)
        {
            for (long long j = i; j <= 1; j++)
            {
                if ( fx2l(i, j) ) ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
