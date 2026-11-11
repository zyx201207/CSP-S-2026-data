#include <bits/stdc++.h>
//#define int long long
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 2e6 + 10; /// change the range
ll a[N];
int l[N], r[N], lo[N], ro[N];
signed main()
{
    freopen ("migrate.in", "r", stdin); ///write the name
    freopen ("migrate.out", "w", stdout); ///write the name
    int c, t; scanf ("%d %d", &c, &t);
    while (t--)
    {
        int n; ll d; scanf ("%d %lld", &n, &d);
        for (int i = 1; i <= n; i++) scanf ("%lld", a + i);
        a[0] = -4e18, a[n + 1] = 4e18, l[0] = r[0] = 0, l[n + 1] = r[n + 1] = n + 1;
        int L = 1, R = 1;
        for (; R <= n; R++)
        {
            if (a[R] - a[L] <= d) continue;
            while (a[R] - a[L] > d) r[L++] = R - 1;
        }
        while (L <= n) r[L++] = n;
        L = n, R = n;
        for (; L >= 1; L--)
        {
            if (a[R] - a[L] <= d) continue;
            while (a[R] - a[L] > d) l[R--] = L + 1;
        }
        while (R >= 1) l[R--] = 1;
        for (int i = 1; i <= n; i++) lo[i] = l[i], ro[i] = r[i];
        for (int i = 1; r[i] < n;)
        {
            int pos = i;
            while (r[pos] != pos)
            {
                if (a[r[pos] + 1] - a[r[pos] - 1] > d) pos = r[pos];
                else break;
            }
            for (; r[i] <= r[pos]; i++) r[i] = r[pos];
            if (r[i] == i)
            {
                i++;
                continue;
            }
        }
        for (int i = n; l[i] > 1;)
        {
            int pos = i;
            while (l[pos] != pos)
            {
                if (a[l[pos] + 1] - a[l[pos] - 1] > d) pos = l[pos];
                else break;
            }
            for (; l[i] >= l[pos]; i--) l[i] = l[pos];
            if (l[i] == i)
            {
                i--;
                continue;
            }
        }
        // for (int i = 1; i <= n; i++) cout << lo[i] << " ";
        // cout << "\n";
        // for (int i = 1; i <= n; i++) cout << ro[i] << " ";
        // cout << "\n";
        // for (int i = 1; i <= n; i++) cout << l[i] << " ";
        // cout << "\n";
        // for (int i = 1; i <= n; i++) cout << r[i] << " ";
        // cout << "\n";
        ll ans = 0;
        for (int i = 2; i < n - 1; i++)
        {
            if (lo[i + 1] == lo[i + 2]) continue;
            if (ro[i] == ro[i - 1]) continue;
            if (lo[i + 1] >= i) continue;
            if (ro[i] <= i + 1) continue;
            int pl = lo[i + 2] - 1, pr = ro[i - 1] + 1;
            // cout << pl << " " << pr << "\n";
            ans += (pl - l[i + 1] + 1) * (r[i] - pr + 1);
        }
        printf ("%lld\n", ans);
    }
    return 0;
}