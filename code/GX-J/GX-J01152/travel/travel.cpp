#include <bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    bool first=false,second=false,third=false,last=false;
    if (a==c)
    {
        first=true;
    }
    if (b[0]*10 +b[1]==d[0]*10+d[1])
    {
        second=true;
    }
    if ((b[0]*10 +b[1]==d[0]*10+d[1]) && (((b[2]=='A') && ((d[2]=='B') || (d[2]=='C'))) || ((b[2]=='B') && ((d[2]=='C') || (d[2]=='A'))) || ((b[2]=='C') && ((d[2]=='A') || (d[2]=='B'))) || (((b[2]=='D') && (d[2]=='F')) || ((d[2]=='D') && (b[2]=='F')))))
    {
        third=true;
    }
    if ((b[0]*10 +b[1]==d[0]*10+d[1]) && ((b[2]=='A' && d[2]=='B') || (b[2]=='B' && d[2]=='A') || (b[2]=='B' && d[2]=='C') || (b[2]=='C' && d[2]=='B') || (b[2]=='D' && d[2]=='F') || (b[2]=='F' && d[2]=='D')))
    {
        last=true;
    }
    cout <<first<<second<<third<<last;
    return 0;
}
