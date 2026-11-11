#include <bits/stdc++.h>
using namespace std;

long long a[500001];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    long long m;
    scanf("%d %lld", &n, &m);
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    long long cnt = 0;
    int res = 0;
    for(int i = 1, j = 1;i <= n;i++)
    {
        while(j < i && cnt > m)
        {
            cnt -= a[i] - a[j];
            j++;
        }
        res = max(res, i - j + 1);
        if(i != n)
        {
            cnt += (a[i + 1] - a[i]) * (i - j + 1);
        }
    }
    printf("%d\n", res);
    return 0;
}
