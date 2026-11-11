#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=5e5+5,P=1e9+7;

int rd()
{
    int x=0,y=1;char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            y=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*y;
}

void wt(int x,char c='~')
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>=10)
        wt(x/10);
    putchar(x%10+'0');
    if(c!='~')
        putchar(c);
}

int n,m,a[N],b[N];

bool check(int k)
{
    for(int i=1;i+k-1<=n;i++)
    {
        int l=i,r=i+k-1;
        int v=k*a[r]-(b[r]-b[l-1]);
        if(v<=m)
            return 1;
    }
    return 0;
}

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=rd();m=rd();
    for(int i=1;i<=n;i++)
        a[i]=rd();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+a[i];
    int l=1,r=n,ans=1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    wt(ans);
    return 0;
}