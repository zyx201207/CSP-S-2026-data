#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 5e5 + 10;

int n;
LL m;
LL a[N], s[N];

bool check(int mid, int x)
{
    int len = x - mid + 1;
    return len * a[x] - (s[x] - s[mid - 1]) <= m;
}

int work(int x)
{
    int l = 1, r = x;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid, x)) r = mid;
        else l = mid + 1;
    }
    return x - l + 1;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i ++ )
        scanf("%lld", &a[i]);

    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++ )
        s[i] = s[i - 1] + a[i];

    int res = 0;
    for (int i = 1; i <= n; i ++ )
        res = max(res, work(i));

    printf("%d\n", res);

    return 0;
}
