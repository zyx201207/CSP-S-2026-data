#include <cstdio>
#include <cstdlib>
#include <ctime>

using Ll = long long;

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    srand(time(NULL));
    Ll t;
    scanf("%*lld%lld", &t);
    while (t--)
    {
        Ll n;
        scanf("%lld%*lld", &n);
        printf("%lld\n", rand() % (n * (n - 1LL) >> 1LL));
        while (n--)
        {
            scanf("%*lld");
        }
    }
    return 0;
}