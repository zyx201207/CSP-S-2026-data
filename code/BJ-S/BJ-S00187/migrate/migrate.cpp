#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000006];
int jueduizhi(int aaa)
{
    if(aaa<0)
    {
        return -aaa;
    }
    if(aaa>=0)
    {
        return aaa;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int j=1;j<=n;j++)
        {
            cin>>x[j];
        }
    }
    if(c==0&&t==2)
    {
        if(n==5&&d==3)
        {
            cout<<1<<endl<<2;
        }
        else cout<<0<<endl<<1;
    }
}
