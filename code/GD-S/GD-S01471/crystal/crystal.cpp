#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int LL
#define For(i, t, n) for (int i = t; i <= n; ++i)
#define foR(i, t, n) for (int i = t; i >= n; --i)
#define isdigit(c) (c >= 48 && c <= 57)
#define gc getchar
void read(int &x)
{
    x = 0;
    int c = gc(), f = 1;
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = gc();
    }
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = gc();
    }
    x *= f;
}
void write(int x)
{
    int stk[100], top = 0;
    if (x < 0)
        putchar('-'), x = -x;
    do
    {
        stk[++top] = x % 10;
        x /= 10;
    } while (x);
    while (top)
        putchar(stk[top--] | 48);
}
const int MAXN = 5e5 + 5;

int n, m;
int a[MAXN], len;
pair<int, int> p[MAXN];
#define fi first
#define se second

void solve()
{
    read(n);
    read(m);
    For(i, 1, n) read(a[i]);
    sort(a + 1, a + n + 1);
    {
        int t = -1e16, cnt = 0;
        For(i, 1, n)
        {
            if (a[i] != t)
            {
                p[len++] = {t, cnt};
                t = a[i];
                cnt = 1;
            }
            else
            {
                ++cnt;
            }
        }
        p[len] = {t, cnt};

        // For(i, 1, len) cerr << p[i].fi << " (" << p[i].se << ")\n";
    }
    int ans = 1, now = p[len].se, r = m, lst = 0, siz = 0;
    For(i, 1, len) ans = max(ans, p[i].se);
    foR(i, len - 1, 1)
    {
        int t = (p[len].fi - p[i].fi) * p[i].se;
        lst = i;
        if (r >= t)
        {
            r -= t;
            now += p[i].se;
        }
        else
        {
            int s = r / (p[len].fi - p[i].fi);
            r -= (p[len].fi - p[i].fi) * s;
            now += s;
            siz = s;
            // cerr << "mx| now=" << now << " r=" << r << '\n';
            break;
        }
        // cerr << "mx| now=" << now << " r=" << r << '\n';
    }
    ans = max(ans, now);
    foR(i, len - 1, 1)
    {
        // assert(now>=1);
        // cerr << "i = " << i << " lst = " << lst << '\n';
        now -= p[i + 1].se;
        r += now * (p[i + 1].fi - p[i].fi);
        now -= siz;
        if (lst == i)
            now += p[i].se, --lst;
        // cerr << "up> now=" << now << " r=" << r << "\n";
        if (!lst)
        {
            ans = max(ans, now);
            break;
        }
        bool f = 0;
        foR(j, lst, 1)
        {
            lst = j;
            int t = (p[i].fi - p[j].fi) * p[j].se;
            if (r >= t)
            {
                r -= t;
                now += p[j].se;
                if (j == 1)
                    f = 1;
            }
            else
            {
                int s = r / (p[i].fi - p[j].fi);
                r -= (p[i].fi - p[j].fi) * s;
                now += s;
                siz = s;
                break;
            }
        }
        ans = max(ans, now);
        if (f)
            break;
        // cerr << "sp| (" << p[i].fi << ") now=" << now << " r=" << r << " ans(" << ans << ")\n";
    }
    write(ans);
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    // freopen("t1.err", "w", stderr);
    solve();
    return 0;
}
