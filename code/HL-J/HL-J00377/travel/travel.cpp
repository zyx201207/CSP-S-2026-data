#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel","r",stdin);
    freopen("travel","w",stdout);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==b)
    {
        if(c==b-1)
        {
            cout<<1111;
        }
        else
        {
            cout<<1100;
        }
    }
    else
    {
        cout<<0<<0<<0<<0;
    }
return 0;
}
