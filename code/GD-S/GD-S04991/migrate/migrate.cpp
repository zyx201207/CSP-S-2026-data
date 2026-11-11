#include <bits/stdc++.h>

using namespace std;

long long c, t, n, d, x[2000010];

inline void tt()
{
    scanf("%d%d", &n, &d);
    for(int i=1;i<=n;i++) scanf("%d", x+i);
    int ans=0;
    for(int i=1;i<=n-3;i++)
    {
        if(x[i+2]-x[i]<=d&&x[i+3]-x[i+1]<=d&&x[i+3]-x[i]>d)
            ans++;
    }
    printf("%d\n", ans);
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    scanf("%d%d", &c, &t);

    while(t--) tt();

    return 0;
}