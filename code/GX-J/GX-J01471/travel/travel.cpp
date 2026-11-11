#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i=1;i<=10;i++)
    {
        if(a==c)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
            break;
        }
        if(b==d)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
            break;
        }
    }
    return 0;
}
