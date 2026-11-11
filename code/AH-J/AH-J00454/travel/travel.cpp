#include <cstdio>

using Ll = long long;

bool g(const char a)
{
    return a == 'D' || a == 'E';
}

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    Ll a, b, d, e;
    char c, f;
    scanf("%lld%lld%c%lld%lld%c", &a, &b, &c, &d, &e, &f);
    printf("%d%d%d%d\n",
        a == d,
        a == d && b == e,
        a == d && b == e && g(c) == g(f),
        a == d && b == e && g(c) == g(f) && (c - f == 1LL || f - c == 1LL));
    return 0;
}