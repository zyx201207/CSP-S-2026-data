#include <bits/stdc++.h>
using namespace std;
long  long c,t,n,d,x[2000009],u,v,sum=0,leng=0,minn=99999999;
void f(long long u,long long v)
{
    if(abs(x[u]-x[u+1])<=d)
    {
        leng++;
        f(u+1,v);
    }
    return leng;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int p=1;p<=t;p++)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<n;i++)
        {
            //u=x[i];
            for(int j=1;j<=n;j++)
            {
                //cout<<f(x[i],x[j])<<endl;
                if(f(x[i],x[j])>0)
                {
                    if(minn==min(minn,f(x[i],x[j])))
                    {
                        sum++;
                    }
                    else
                    {
                        sum=0;
                    }
                    minn=min(minn,f(x[i],x[j]));

                }
            }

        }
    }
    cout<<sum;
    return 0;
}
