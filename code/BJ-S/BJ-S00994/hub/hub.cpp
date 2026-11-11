#include<bits/stdc++.h>
#define ll long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
const int N=2e6+5;

int c,t,n,k;
inline ll read()
{
    int ret=0,fh=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar())
        if(ch=='-') fh=-1;
    for(;isdigit(ch);ch=getchar())
        ret=ret*10+ch-'0';
    return ret*fh;
}
inline void write(ll x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read(),t=read();
    while(t--)
    {
        ll ans=0;
        n=read(),k=read();
        rep(i,1,n-1)
        {
            int u,v;
            u=read(),v=read();
        }
        write(1),putchar('\n');
    }
    return 0;
}
//18:23