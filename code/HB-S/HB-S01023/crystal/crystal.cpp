#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5+50;
int n,m,ans;
int a[maxn],sum[maxn];
int read()
{
    int f = 1,k = 0;
    char c = getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f = -1;
        c = getchar();
    }
    while(c>='0'&&c<='9')
    {
        k = k*10+c-'0';
        c = getchar();
    }
    return f*k;
}
bool check(int mid,int i)
{
    return (a[i]*(i-mid)-(sum[i-1]-sum[mid-1]))<=m;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n = read(),m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    sort(a+1,a+1+n);
    for(int i = 1;i<=n;i++)
        sum[i] = sum[i-1] + a[i];
    for(int i = n;i>=1;i--)
    {
        int l = 1,r = i-1;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(check(mid,i))
            {
                ans = max(i - mid + 1,ans);
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
Oct31==Dec25?
*/