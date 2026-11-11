#include <bits/stdc++.h>
#define int ll
#define fi first
#define endl '\n'
#define se second
#define il inline
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e5 + 10;
int n, m, a[N], pre[N];
int check(int x)
{
    for (int i = 1; i + x - 1 <= n; i++)
    {
        int j = i + x - 1;
        if (x * a[j] - pre[j] + pre[i - 1] <= m)
            return 1;
    }
    return 0;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    int l = 1, r = n, ans = 0;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}