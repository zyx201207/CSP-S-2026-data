#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    if(a!=b)cout<<"0000";
    else if(c[1]!=d[1]||c[0]!=d[0])cout<<"1000";
    else if(c[2]<='C'&&d[2]<='C')
    {
        if(abs(c[2]-d[2])==2)cout<<"1110";
        else cout<<"1111";
    }
    else if(c[2]>'C'&&d[2]>'C')cout<<"1111";
    else cout<<"1100";
    return 0;
}
