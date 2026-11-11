#include<bits/stdc++.h>
#define int long long
#define maxn 1000006
int n,m,a[maxn],s[maxn],ans;
inline int read()
{
    int x = 0,f = 1;char ch = getchar();
    while(ch<'0'||ch>'9')f = ch == '-'?-f:f,ch = getchar();
    while(ch>='0'&&ch<='9')x = (x<<3)+(x<<1)+(ch^'0'),ch = getchar();
    return x*f;
}
inline void write(int x)
{
    if(x<0)putchar('-'),x = -x;
    static char sta[35];int top = 0;
    do sta[top++] = x%10,x/=10;while(x);
    while(top)putchar(sta[--top]^'0');
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n = read(),m = read();
    for(int i = 1;i<=n;++i)a[i] = read();
    std::sort(a+1,a+1+n);
    for(int i = 1;i<=n;++i)s[i] = s[i-1]+a[i];
    for(int i = n,l,r,mid;i;--i)
    {
        l = 0,r = i;
        while(l!=r)
        {
            mid = (l+r)>>1;
            if((i-mid)*a[i]-(s[i]-s[mid])>m)
                l = mid+1;
            else r = mid;
        }
        ans = std::max(ans,i-l);
    }
    write(ans);
    return 0;
}
