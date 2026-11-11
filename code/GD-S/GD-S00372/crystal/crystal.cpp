#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500010;
int n;
ll m, a[N], sum[N];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++)scanf("%lld", a + i);
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++)sum[i] = sum[i - 1] + a[i];
    int sl = 1, ans = 1;
    for(int i = 1; i <= n; i++)
    {
        while(a[i] * (i - sl + 1) - (sum[i] - sum[sl - 1]) > m)sl++;
        ans = max(ans, i - sl + 1);
    }
    printf("%d\n", ans);
    return 0;
}
