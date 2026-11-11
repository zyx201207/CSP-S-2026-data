#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int N = 5005;
int C, T, n, d, x[N], f[N], ans;

struct bit
{
    int t[N];
    void add(int k, int x)
    {
        if (!k) return;
        while (k <= n)
        {
            t[k] += x;
            k += k & -k;
        }
    }
    int ask(int x)
    {
        int res = 0;
        while (x)
        {
            res += t[x];
            x ^= x & -x;
        }
        return res;
    }
    int query(int l, int r)
    {
        return ask(r) - ask(l-1);
    }
}t;

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> C >> T;
    while (T--)
    {
        cin >> n >> d;
        ans = 0;
        for (int i = 1; i <= n; ++i) cin >> x[i];
        for (int i = 1; i <= n; ++i)
        {
            for (int i = 1; i <= n; ++i) t.t[i] = 0;
            f[i] = 0;
            t.add(i, 1);
            for (int j = i+1; j <= n; ++j)
            {
                int l = i, r = j-1, pl = -1, pr = -1;
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if (x[j] - x[mid] <= d)
                    {
                        r = mid-1;
                        pl = mid;
                    }
                    else l = mid+1;
                }
                if (pl == -1) break;
                l = i, r = j-1;
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if (f[mid] <= f[pl])
                    {
                        l = mid+1;
                        if (f[mid] == f[pl]) pr = mid;
                    }
                    else r = mid-1;
                }
                f[j] = f[pl]+1;
                int sum = t.query(pl, pr);
                t.add(j, sum);
                if (sum == 2) ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
