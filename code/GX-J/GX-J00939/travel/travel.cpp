#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2;
    long long b1,b2;
    char c1,c2;
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    if(a1!=a2)
    {
        cout<<0;
    }
    else
    {
        cout<<1;
    }
    if(a1==a2&&b1==b2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(a1==a2&&b1==b2&&c1<='C'&&c2<='C'||a1==a2&&b1==b2&&c1>'C'&&c2>'C')
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(a1==a2&&b1==b2&&c1<='C'&&c2<='C'&&c1+1==c2||c2+1==c1||a1==a2&&b1==b2&&c1>'C'&&c2>'C')
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
