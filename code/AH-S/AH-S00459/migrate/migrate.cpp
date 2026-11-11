#include<bits/stdc++.h>

using namespace std;
long long read()
{
char ch;
long long w=1,s=0;
ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') w=-1;
    ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
    s=s*10+ch-'0';
    ch=getchar();
    }
return w*s;
}
int c,t,n;
long long x[2000005],d;

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();
    t=read();
    while(t--)
    {
    n=read();
    d=read();
        for(int i=1;i<=n;i++)
        {
        x[i]=read();
        }
        if(c==11 || c<=12)
        {
        long long dis=x[2]-x[1],p;
            if(d<dis*2) cout<<0<<endl;
            else
            {
            p=d/dis;
                if(n<=p*2) cout<<0<<endl;
                else cout<<n-p*2+1<<endl;
            }
        }
    }
    return 0;
}
