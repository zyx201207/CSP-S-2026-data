#include<bits/stdc++.h>
#define fir first
#define sec second
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
    ll x=0,t=1;
    char c=getchar();
    while(c<'0' || c>'9')
    {
        if(c=='-')
            t=-1;
        c=getchar();
    }
    while(c>='0' && c<='9')
    {
        x=(x<<1)+(x<<3)+(c^'0');
        c=getchar();
    }
    return x*t;
}
inline void write(ll x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>=10) write(x/10);
    putchar((x%10)^'0');
    return ;
}
inline void write_L(ll x)
{
    write(x);
    putchar('\n');
}
inline void write_(ll x)
{
    write(x);
    putchar(' ');
}
inline void write_P(pll x)
{
    write_(x.fir);
    write_L(x.sec);
}
const int N=5e5+10;
ll a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n=read(),m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+n+1);
    ll sum=0,num=0,ans=0;
    for(int r=1,l=0;r<=n;r++)
    {
        sum=sum+num*(a[r]-a[r-1]);
        num++;
        while(sum>m)
        {
            sum-=a[r]-a[l];
            l++;
            num--;
        }
        ans=max(ans,num);
    }
    write_L(ans);
    return 0;
}
// 100pts on 14:55:00
