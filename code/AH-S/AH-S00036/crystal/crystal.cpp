#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

constexpr int MAXN = 5e5;
int n;
LL m, a[MAXN + 5];

int cnt(int key, int key_id)
{
    int x = m, c = 0;
    for (int i = key_id; i >= 1; --i)
    {
        LL cost = key - a[i];
        x -= cost;
        if (x >= 0)
        {
            ++c;
        }
        else
        {
            break;
        }
    }
    return c;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    LL l = 1e12, r = -1e12;
    int max_ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    sort(a + 1, a + n + 1);
    int l_id = 1;
    for (l; l <= r; ++l)
    {
        l_id = upper_bound(a + 1, a + n + 1, l) - a - 1;
        l = a[l_id] > l ? a[l_id] : l;
        int ans = cnt(l, l_id);
        if (ans < max_ans - (n - l_id))
        {
            break;
        }
        max_ans = max(max_ans, ans);
    }

    cout << max_ans;

    return 0;
}
