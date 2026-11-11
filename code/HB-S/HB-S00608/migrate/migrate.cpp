#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
#define ull unsigned long long
#define N 1000005
using namespace std;

ll rd(){char c=getchar();ll f=1,x=0;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0',c=getchar();}return f*x;}

ll C, T, n, d, f[305][305], a[N];
int dis[5005];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    C = rd(), T = rd();
    while (T--)
    {
        n = rd(), d = rd();
        for (int i = 1; i <= n; i++) a[i] = rd();
        ll ff = 1;
        for (int i = 3; i <= n; i++) ff &= (a[i]-a[i-1]==a[2]-a[1]);
        // if (n == 1) { cout << '0\n'; continue; }
        if (ff)
        {
            // cout << "\n--------------------\n";
            ll x = d / (a[2] - a[1]), res = 0;
            // cout << x << " " << n << '\n';
            if (x < 2) cout << "0\n";
            else cout << max(0ll, n - (x*2-1)) << '\n';
        }
        else if (n <= 300)
        {
            int res = 0;
            for (int i = 1; i <= n; i++)
            {
                f[i][0] = 1;
                dis[i] = 0;
                for (int j = i+1; j <= n; j++)
                {
                    dis[j] = -1;
                    for (int o = 0; o <= j-i+1; o++) f[j][o] = 0;
                    for (int k = j-1; k >= i; k--)
                    {
                        if (a[j] - a[k] > d) break;
                        for (int o = dis[k]; o <= k-i+1; o++) 
                        {
                            if (f[j][o] > 2) break;
                            f[j][o+1] += f[k][o];
                            // if (dis[j] != -1 && f[j][o+1]) dis[j] = o+1;
                        }
                    }
                    for (int o = 1; o <= j-i+1; o++)
                    {
                        if (f[j][o])
                        {
                            // cout << "(" << i << "," << j << "," << o << ")" << "=" << f[j][o] << '\n';
                            dis[j] = o;
                            res += (f[j][o] == 2);
                            break;
                        }
                    }
                }
            }
            cout << res << '\n';
        }
    }
    return 0;
}
/*
g++ migrate.cpp -std=c++14 -O2 -o migrate && time ./migrate
0 1
10 3
0 3 6 7 8 9 10 13 16 19
*/