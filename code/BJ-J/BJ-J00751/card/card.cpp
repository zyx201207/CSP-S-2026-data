#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, nn;
const int N = 500005, M = 300005;

int a[N], lst[N], ans[N], cnt[N];
int na[N];

void bf()
{
    for (int st = 1; st <= n; st++)
    {
        for (int i = 1; i <= m; i++)
            lst[i] = 0;
        for (int i = st; i <= n; i++)
        {
            if (lst[a[i]] > 0)
            {
                for (int j = lst[a[i]]; j < i; j++)
                    lst[a[j]] = 0;
            }
            lst[a[i]] = i;
        }
        for (int i = 1; i <= m; i++)
            ans[i] += (lst[i] > 0);
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
}

void sp_b()
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i - 1])
            na[++nn] = a[i];
        cnt[a[i]]++;
    }
    n = nn;
    for (int i = 1; i <= n; i++)
        a[i] = na[i];
    for (int st = 1; st <= n; st++)
    {
        for (int i = 1; i <= m; i++)
            lst[i] = 0;
        for (int i = st; i <= n; i++)
        {
            if (lst[a[i]] > 0)
            {
                for (int j = lst[a[i]]; j < i; j++)
                    lst[a[j]] = 0;
            }
            lst[a[i]] = i;
        }
        for (int i = 1; i <= m; i++)
            ans[i] += (lst[i] > 0) * cnt[i];
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
}

void sp_a()
{
    for (int i = 1; i <= n; i++)
        ans[a[i]]++;
    for (int i = 1; i <= m; i++)
    {
        ans[i] += ans[i - 1];
        cout << ans[i] << ' ';
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n <= 5000) bf();
    else if (m <= 3000) sp_b();
    else sp_a();
}

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
//lemon road, i'll love you 4 ever
//100 + 100 + 100 + 52 = 352 points!!!
