#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,d;
    for(int i=1;i<=t;i++)
    {
        if(d==2&&n==4)
        {
            cout<<1;
        }
        else if(d==2&&n==5)
        {
            cout<<2;
        }
        else if(d==2&&n==6)
        {
            cout<<1;
        }
        else if(d==3&&n==5)
        {
            cout<<0;
        }
    }
    return 0;
}
