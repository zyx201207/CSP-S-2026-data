#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005], b[500005], ans[500005];
void abc(long long x)
{
    long long cnt=0;
    memset(b, 0, sizeof(b));
    for(long long i=x;i<=n;i++)
    {
        long long y=-1;
        for(long long j=1;j<=cnt;j++)
        {
            if(b[j]==a[i])
            {
                y=j;
                break;
            }
        }
        if(y==-1) b[++cnt]=a[i];
        else
        {
            for(long long j=y;j<=cnt;j++)
            {
                b[j]=0;
            }
            cnt=y;
            b[cnt]=a[i];
        }
    }
    for(long long i=1;i<=cnt;i++)
    {
        ans[b[i]]++;
    }
}
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for(long long i=1;i<=n;i++) scanf("%lld", &a[i]);
    for(long long i=1;i<=n;i++) abc(i);
    for(long long i=1;i<=m;i++) printf("%lld ", ans[i]);
    return 0;
}