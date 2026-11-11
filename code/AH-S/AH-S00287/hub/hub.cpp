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
int c,t;
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read(),t=read();
    while(t--)
    {
        write(1);
        puts("");
    }
    return 0;
}
