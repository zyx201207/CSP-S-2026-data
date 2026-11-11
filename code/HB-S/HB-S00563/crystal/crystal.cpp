#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define gc getchar
template<typename T>
inline T rd()
{
    T x = 0, f = 1;
    char c = gc();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = gc();
    }
    while (isdigit(c))
        x = x * 10 + c - '0', c = gc();
    return x * f;
}

const int N = 500010;
int n, maxn = 1;
ll m, a[N], s[N];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int l, r, mid, ans;
    n = rd<int>(), m = rd<ll>();
    for (int i = 1; i <= n; i++)
        a[i] = rd<ll>();
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
    {
        l = 1, r = i, ans = 0x3f3f3f3f;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (((a[i] * (i - mid) - (s[i - 1] - s[mid - 1])) <= m))
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        maxn = max(maxn, i - ans + 1);
    }
    printf("%d\n", maxn);
    return 0;
}