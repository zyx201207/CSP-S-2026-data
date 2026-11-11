#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,e,d,y,u;
    char c,f;
    cin>>a>>b>>c>>d>>e>>f;
    if(a==d)
    {
        cout<<1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(b==e)
    {
        cout<<1;
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(c>='A'&&c<='C')
        y=0;
    else
        y=1;
    if(f>='A'&&f<='C')
        u=0;
    else
        u=1;
    if(y==u)
    {
        cout<<1;
        if(f==c-1||f==c+1)
            cout<<1;
        else
            cout<<0;
    }
    else
    {
        cout<<"00";
    }
    return 0;
}