#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500007];
long long m;
int h,t;
int ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a + 1, a + 1 + n);
    h = 1;
    t = 2;
    while(h < n)
    {
        while(m >= (t - h) * (a[t] - a[t - 1]) and t < n)
        {
            m = m - ((t - h) * (a[t] - a[t - 1]));
            t++;
        }
        if(t - h > ans) ans = t - h;
        m = m + a[t - 1] - a[h];
        h++;
    }
    printf("%d",ans);
    return 0;
}