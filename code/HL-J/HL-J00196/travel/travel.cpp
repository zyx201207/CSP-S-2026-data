#include <bits/stdc++.h>
using namespace std;
bool f(char x)
{
    if(x=='D'||x=='F')
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char c1,c2;
    cin>>a>>b>>c1>>c>>d>>c2;
    if(a!=c)
    {
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(b!=d)
    {
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(f(c1)==f(c2))
    {
        cout<<1;

    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(abs(c1-c2)==1)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
