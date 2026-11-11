#include<cstdio>
#include<algorithm>
using namespace std;

int n, l = 1, ans;
long long m, s, a[500005];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        s += a[i];
        while(a[i] * (i - l + 1) - s > m)
        {
            s -= a[l];
            l++;
        }
        ans = max(ans, i - l + 1);
    }
    printf("%d", ans);
    return 0;
}
