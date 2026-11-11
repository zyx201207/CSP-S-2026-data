#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t=0,w=1,an=0;
bool pif(long long x,long long y,long long z)
{
    int u=0;
    while(y>=10)
    {
        u++;
        y/=10;
    }
    int v=0;
    while(y>=10)
    {
        v++;
        z/=10;
    }
    if(u+v>18||(x*y>1&&v+u>=18)||(x*y>10&&v+u>=17))
    {
        return 1;
    }
    for(int i=1;i<=u;i++)
    {
        y*=10;
    }
    for(int i=1;i<=v;i++)
    {
        z*=10;
    }
    return x<(y*z);
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    while(1)
    {
        if(t+1>n)
        {
            break;
        }
        if(pif(m,a[t+1]-a[t],t-w+1))
        {
            if(t<w)
            {
                t++;
                w++;
            }
            else
            {
                m+=a[t]-a[w];
                w++;
            }
        }
        m-=(a[t+1]-a[t])*(t-w+1);
        t++;
        an=max(an,t-w+1);
    }
    cout<<an;
    return 0;
}