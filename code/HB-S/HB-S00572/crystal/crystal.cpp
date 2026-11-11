#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void read(int &a)
{
    int s=0,w=1;
    char ch=getchar();
    while (ch < '0' or ch > '9')
    {
        if (ch == '-')
        {
            w=-1;
        }
        ch=getchar();
    }
    while (ch >= '0' and ch <='9')
    {
        s=s*10+ch-'0';
        ch=getchar();
    }
    a=s*w;
}
void write(int x)
{
    if (x < 0)
    {
        putchar('-');
        x=-x;
    }
    if (x > 9)
    {
        write(x/10);
    }
    putchar('0'+x%10);
    return;
}
int a[500005];
int sum[500005],m;
int solve(int pos)
{
    int l=1,r=pos;
    int mid,ans=0;
    while (l <= r)
    {
        mid=(l+r)/2;
        if (a[pos]*(pos-mid+1)-(sum[pos]-sum[mid-1]) <= m)
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    read(n),read(m);
    for (int i = 1;i <= n;i++)
    {
        read(a[i]);
    }
    sort(a+1,a+1+n);
    for (int i = 1;i <= n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int maxn=0;
    for (int i = 1;i <= n;i++)
    {
        maxn=max(maxn,i-solve(i)+1);
    }
    write(maxn);
    return 0;
}