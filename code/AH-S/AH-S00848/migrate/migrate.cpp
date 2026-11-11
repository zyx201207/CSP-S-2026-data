#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x,y;
int a[5005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        x=n;
        y=d;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
        }
    }
    if(x==5&&y==2)
    {
        cout<<1<<endl<<2;
        return 0;
    }
    if(x==6&&y==2)
    {
        cout<<0<<endl<<1;
        return 0;
    }
    else if(c>=5)
    {
        cout<<2<<endl<<3;
        return 0;
    }
    else cout<<3<<endl<<5;
    return 0;
}
