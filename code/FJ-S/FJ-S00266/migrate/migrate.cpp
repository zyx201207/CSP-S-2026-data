#include<cstdio>
#include<algorithm>
using namespace std;

int c, t, n, l[2000005], r[2000005], ls[2000005], rs[2000005];
long long d, x[2000005], ans;

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while(t--)
    {
        scanf("%d%lld", &n, &d);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &x[i]);
        l[1] = 1;
        r[0] = 0;
        for(int i = 2; i <= n; i++)
        {
            l[i] = l[i - 1];
            while(x[i] - x[l[i]] > d) l[i]++;
        }
        r[n] = n;
        l[n + 1] = n + 1;
        for(int i = n - 1; i >= 1; i--)
        {
            r[i] = r[i + 1];
            while(x[r[i]] - x[i] > d) r[i]--;
        }
        for(int i = 1; i <= n; i++)
            ls[i] = rs[i] = 0;
        for(int i = 1; i <= n; i++)
            if(r[i] != i)
            {
                if(l[r[i]] == i) ls[r[i]] += ls[i];
                ls[r[i]]++;
            }
        for(int i = n; i >= 1; i--)
            if(l[i] != i)
            {
                if(r[l[i]] == i) rs[l[i]] += rs[i];
                rs[l[i]]++;
            }
        ans = 0;
        for(int i = 1; i <= n - 1; i++)
            if(r[i] > i + 1 && l[i + 1] < i)
            {
                int x = rs[i], y = ls[i + 1];
                if(l[i] != l[i + 1]) y = l[i + 2] - l[i + 1];
                if(r[i] != r[i + 1]) x = r[i] - r[i - 1];
                ans += 1ll * x * y;
            }
        printf("%lld\n", ans);
    }
    return 0;
}
