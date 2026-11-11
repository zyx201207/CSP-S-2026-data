#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 200000;
pair<int, char> a[MAXN + 5];
int n;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].first >> a[i].second;
    }

    int l = 1, r = n;
    long long cnt = 0;
    while (l <= r)
    {
        int b = min(a[l].first, a[r].first);
        if (a[l].second != a[r].second)
        {
            cnt += b;
        }
        a[l].first -= b;
        a[r].first -= b;
        if (l == r)
        {
            a[l].first += b;
        }
        if (a[l].first == 0)
        {
            ++l;
        }
        if (a[r].first == 0)
        {
            --r;
        }
    }

    cout << cnt;

    return 0;
}
