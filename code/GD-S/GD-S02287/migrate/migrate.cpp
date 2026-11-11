
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

using ll = long long;

const int N = 2e6;

int n;
ll d;
vector<ll> x(N);

int cnt = 0, mins = N;

inline void dfs(int u, int tg, int st)
{
    if (u == tg)
    {
        if (st < mins)
        {
            mins = st;
            cnt = 1;
            // cout << "NEW " << st << "\n";
        }
        else if (st == mins)
        {
            ++cnt;
            // cout << "CN " << cnt << "\n";
        }
    }
    for (int i = u + 1; i <= tg; ++i)
    {
        if (x[i] - x[u] > d)
        {
            break;
        }

        dfs(i, tg, st + 1);
    }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);

    while (t--)
    {
        scanf("%d%lld", &n, &d);

        for (int i = 0; i < n; ++i)
        {
            scanf("%lld", &x[i]);
        }

        if (n <= 20)
        {
            ll ans = 0;
            for (int u = 0; u < n; ++u)
            {
                for (int v = u + 1; v < n; ++v)
                {
                    // cout << "S " << u << " " << v << "\n";
                    cnt = 0;
                    mins = N;
                    dfs(u, v, 0);

                    if (cnt == 2)
                    {
                        ++ans;
                        // cout << "OK " << u << " " << v << "\n";
                    }
                }
            }

            printf("%d\n", ans);
            continue;
        }

        ll cnt = 0;
        for (int u = 0; u < n; ++u)
        {
            for (int v = u + 1; v < n; ++v)
            {
                // cout << u << " " << v << "\n";
                int inc = 0;
                if (x[u + 1] - x[u] > d || x[u + 2] - x[u + 1] > d)
                {
                    // cout << "0\n";
                    continue;
                }
                for (int i = u + 3; i <= v; ++i)
                {
                    if (x[i] - x[i - 2] <= d && x[i - 1] - x[i - 3] <= d && x[i] - x[i - 3] > d)
                    {
                        if (i >= u + 4 && x[i] - x[i - 4] <= d)
                        {
                            // cout << "1\n";
                            inc = 0;
                            break;
                        }
                        else
                        {
                            if (inc)
                            {
                                inc = 0;
                                // cout << "2\n";
                                break;
                            }
                            ++inc;
                        }
                    }
                    // else
                    // cout << "miss\n";
                    if (x[i] - x[i - 1] > d)
                    {
                        inc = 0;
                        // cout << "3\n";
                        // cout << "E" << x[i] << " " << x[i - 1] << "\n";

                        break;
                    }
                }

                if (inc)
                {
                    ++cnt;
                    // cout << 'A' << u << " " << v << "\n";
                }
            }
        }

        printf("%d\n", cnt);
    }
    return 0;
}
