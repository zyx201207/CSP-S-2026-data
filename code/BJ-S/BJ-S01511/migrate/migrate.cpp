#include<cmath>
#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int N = 2e6 + 10;
const int NN = 5e3 + 10;

int n;
ll d;
ll a[N];
int f[NN];
int g[NN];
int nxt[N];

void work(int st)
{
    for(int i = st; i <= n; i++)
    {
        f[i] = 1e9;
        g[i] = 0;
    }
    f[st] = 0;
    g[st] = 1;
    for(int x = st; x <= n; x++)
    {
        if(g[x] == 0) break;
        if(g[x] > 2) g[x] = 3;
        for(int y = x + 1; y <= nxt[x]; y++)
        {
            if(f[y] > f[x] + 1)
            {
                f[y] = f[x] + 1;
                g[y] = 0;
            }
            if(f[y] == f[x] + 1) g[y] += g[x];
        }
    }
}

void solve(int c)
{
    cin >> n >> d;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    if(n == 1)
    {
        cout << "0\n";
        return;
    }
    if(a[n] - a[1] <= d)
    {
        cout << "0\n";
        return;
    }
    if(11 <= c && c <= 12)
    {
        ll t = d / (a[2] - a[1]);
        if(t <= 1)
        {
            cout << "0\n";
            return;
        }
        t = min(t,n * 1ll);
        cout << max(0ll,n - (2ll * t - 1)) << "\n";
    }
    else
    {
        nxt[n] = n;
        for(int i = n - 1; i >= 1; i--)
        {
            nxt[i] = nxt[i + 1];
            while(a[nxt[i]] - a[i] > d) nxt[i]--;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            work(i);
            for(int j = i; j <= n; j++)
                ans += (g[j] == 2);
        }
        cout << ans << "\n";
    }
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin >> c >> t;
    while(t--) solve(c);
    return 0;
}
