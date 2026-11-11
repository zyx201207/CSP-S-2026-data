#include <bits/stdc++.h>
using namespace std;
char c;
char s[2000000001];
long long i = 0, sum, ans = 0, n, a;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    scanf ("%lld", &n);
    for (int j = 1; j <= n; j++)
    {
        scanf("%lld %c", &a,&c);
        for (int k = 1; k <= a; k++)
        {
            i++;
            s[i] = c;
        }
    }
    sum = i;

    for (i = 1; i <= sum/2; i++)
    {
        if (s[i] != s[sum-i+1])
        {
            ans++;
        }
    }

    printf ("%lld", ans);
    return 0;
}
