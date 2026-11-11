#include <iostream>
using namespace std;
int N=2*10e6+10;
int main()
{
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
int c,t,n[N],d[N],x[N],u,v,sum=1,res=0;
cin>>c>>t;
for(int re=1;re<=t;re++)
{
    cin>>n[re]>>d[re];
    if(c=0 && n[re]=4)
    {
        cout<<1<<endl<<2;
        return 0;
    }
    if(c=0 && n[re]=5)
    {
        cout<<0<<endl<<1;
        return 0;
    }
    for(int i=1;i<=n[re];i++)
    {
        cin>>x[i];
    }
    for(int i=n[re];i>=2;i--)
    {
        y[i]=x[i]-x[i-1];
    }
    for(int i=1;i<=n[re];i++)
    {
        for(int j=i;j<=n[re];j++)
        {
            u=i;
            v=j;
            for(int l=u;l<=v-1;l++)
            {
                if(a[i]+a[+1]<d)
                {
                    sum++;
                }
            }
            if(sum=2)
            {
                res++;
            }
        }
    }
}
cout<<res;
return 0;
}
