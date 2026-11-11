#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1e6+5;


long long c,t;
long long x[maxn];

void init()
{
    cin >> c >> t;
}

long long ans = 0;
long long n,d;
long long f[maxn];

void work()
{
    while(t--)
    {
        ans = 0;
        cin >> n >> d;
        
        bool flagA = 1;
        for(long long i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        // // flagA = 0;
        // if(x[n] - x[1] <= 10 * d)
        // {
        //     cout << n << " " << d <<  "     " << x[n] - x[1] << endl;
        //     continue;
        // }

        long long dx = x[2] - x[1];
        for(long long i = 2; i <= n; i++)
        {
            if(dx != (x[i] - x[i-1]))
            {
                break;
                flagA = 0;
            }
        }

        if(flagA)
        {
            // cout << n << " " << d << " " << dx << "       ";
            if(dx > d)
            {
                cout << 0 << endl;
                continue;
            }
            if(dx == d)
            {
                cout << 0 << endl;
                continue;
            }
            long long ans = n - (d / dx) * 2 + 1;
            if(ans < 0)
            {
                cout << 0 << endl;
                continue;
            }
            cout << ans << endl;
            continue;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    init();
    work();
    return 0;
}