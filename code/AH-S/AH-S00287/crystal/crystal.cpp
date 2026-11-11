#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
inline void write(int x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
const int N=5e5+10;
int a[N],b[N];
int n,m,l,r,mid,ans=1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;++i)a[i]=read();
    sort(a+1,a+n+1);
    for(int i=2;i<=n;++i)b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
    l=2,r=2;
    while(r<=n)
    {
        if(b[r]-b[l-1]-(a[r]-a[l-1])*(l-2)<=m)
        {
            ans=max(ans,r-l+2);
            r++;
        }
        else
        {
            if(l==r)r++;
            l++;
        }
    }
    write(ans);
    return 0;
}
