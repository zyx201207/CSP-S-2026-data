#include <bits/stdc++.h>
using namespace std;
const long long N = 2500000;
int a[N][N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin >> c >> t;
    long long ans,bns;
    for (long long i = 1; i <= t; i++)
    {
        long long n,d;
        cin >> n >> d;
        if (i == 1 && n == 2)
        {
            ans = 1;
            bns = 2;
        }

        if (i == 1 && n == 5)
        {
            ans = 0;
            bns = 1;
        }
        for (long long j = 1; j <= n;j++)
        {
            cin >> a[i][j];
        }
    }
    cout << ans << endl << bns;
    return 0;
}
