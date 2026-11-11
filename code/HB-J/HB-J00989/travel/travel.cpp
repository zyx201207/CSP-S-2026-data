#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d,e[10];
    cin>> a >> b >> c >> d;
    if(a==c) e[0]='1';
    else
    {
        cout << "0000";
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1]) e[1]='1';
    else
    {
        cout << "1000";
        return 0;
    }
    if(b[2]+d[2]==131 ||b[2]+d[2]==133 ||b[2]+d[2]==138 || b[2]+d[2]==132) e[2]='1';
    else
    {
        cout << "1100";
        return 0;
    }
    if(b[2]+d[2]==131 ||b[2]+d[2]==133 || b[2]+d[2]==138) e[2]='1';
    else
    {
        cout << "1110";
        return 0;
    }
    cout << "1111";
    return 0;
}
