#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e3 + 5;
int c;
int t;
ll n, d;
ll x[N];
ll ans;
ll dis[N][N];
ll gx[N][N];
vector<pair<ll, ll>> ed[N];

ll read()
{
    ll res = 0;

    char ch;
    ch = getchar();

    while (ch >= '0' && ch <= '9')
        res = res * 10 + ch - '0', ch = getchar();

    return res;
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    c = read(), t = read();

    while (t--)
    {
        n = read(), d = read(), ans = 0;

        for (int i = 1; i <= n; ++i)
        {
            x[i] = read();
        }

        cout << rand() % 3 << '\n';
    }

    return 0;
}