#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = (int)2e5 + 5;
int n, m, ans;

struct node
{
    int num, cnt;
} a[MAXN];

bool cmp(node x, node y)
{
    if (x.cnt != y.cnt) return x.cnt > y.cnt;
    return x.num >= y.num;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i <= n + 5; i++)
        a[i].num = a[i].cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].num;
        int x = a[i].num;
        while (x > 0)
        {
            if (x % 2 == 1)
                a[i].cnt++;
            x /= 2;
        }
    }
    sort(a + 1, a + n + 1, cmp);
    int ans = a[1].num;
    for (int i = 2; i <= m; i++)
        ans &= a[i].num;
    cout << ans;
    return 0;
}
