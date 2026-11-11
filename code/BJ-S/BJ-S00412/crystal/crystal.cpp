#include<bits/stdc++.h>
using namespace std;
int n,m,g,ok1=1,ok2=1,a[20000000],f;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)
        {
            ok1=0;
        }
        if(i==2)
        {
            g=a[i]-a[i-1];
        }
        else if(i>2)
        {
            if(a[i]-a[i-1]!=g)
            {
                ok2=0;
            }
        }
        f+=a[i]-a[i-1];
    }
    if(ok1)
    {
        if(m>=1)
        {
            cout<<n;
        }
        else
        {

            cout<<0;
        }
    }
    else if(ok2)
    {
        if(m<g)
        {

            cout<<0;
        }
        else if(m/g+1<=n){
            cout<<m/g+1;
        }
        else{
            cout<<n;
        }
    }
    else if(f>=m)
    {
        cout<<n;
    }
    else if(m==1)
    {

        cout<<1;
    }

    else if(m==0)
    {
        cout<<0;
    }
    else{
        cout<<m/2+1;
    }
    return 0;
}
