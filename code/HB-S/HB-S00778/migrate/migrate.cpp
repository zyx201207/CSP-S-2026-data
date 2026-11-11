#include <bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
    int a=0;int b=1;char c=getchar();
    while(c<'0'||c>'9')
    {
        if (c=='-')
        {
            b=-1;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        a=(a<<3)+(a<<1)+c-'0';
        c=getchar();
    }
    return a*b;
}
int c,t,n,d;
int x[2000006];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();t=read();
    for(int i=1;i<=t;i++)
    {
        memset(x,0,sizeof(x));
        n=read();d=read();
        for (int i=1;i<=n;i++)
        {
            x[i]=read();
        }
        if(d<=abs(x[1]-x[3]))
        {
            cout<<0<<endl;
            continue;
        }
        cout<<n-3<<endl;
    }
    return 0;
}