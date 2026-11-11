#include <cstdio>
#include <cstdlib>
#include <ctime>

using Ll = long long;

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    srand(time(NULL));
    Ll t;
    scanf("%*lld%lld", &t);
    while (t--)
    {
        Ll n;
        scanf("%lld%*lld", &n);
        printf("%lld\n", rand() % (n - 1LL));
        while (--n)
        {
            scanf("%*lld%*lld");
        }
    }
    return 0;
}