#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>>b&&a>>c&&a>>d)cout<<a<<b<<c<<d<<endl;
    if(b>>a&&b>>c&&b>>d)cout<<b<<a<<c<<d<<endl;
    if(c>>a&&c>>b&&c>>d)cout<<c<<a<<b<<d<<endl;
    if(d>>a&&d>>b&&d>>c)cout<<d<<a<<b<<c<<endl;
    return 0;
}



