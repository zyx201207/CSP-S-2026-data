#include <bits/stdc++.h>
using namespace std;

long long n, m, a[200005], t[200005], ans = -1;

void dfs(long long x)
{
    if(x > m)
    {
        for(long long i = 1; i <= m-1; i++)
        {
            for(long long j = i+1; j <= m; j++)
            {
                if(t[i] == t[j]) return;
            }
        }
        long long sum = a[t[1]];
        for(long long i = 2; i <= m; i++)
        {
            if(t[i] == t[i-1]) return;
            sum = sum & a[t[i]];
        }
        ans = max(ans, sum);
        return;
    }
    for(long long i = 1; i <= n; i++)
    {
        t[x] = i;
        dfs(x+1);
    }
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(long long i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    dfs(1);
    printf("%d", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

