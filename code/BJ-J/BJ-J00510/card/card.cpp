#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int n, m, a[500005], r[300005], cnt[300005], siz[500005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        r[a[i]] = i;
        siz[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        siz[r[a[i]] + 1] += siz[i];
        cnt[a[i]] += siz[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
