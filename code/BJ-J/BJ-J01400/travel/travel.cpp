#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    string s,ss,n;
    int c,cc,f=1,ff=1,fff=1,ffff=1;
    cin>>c>>s>>cc>>ss;
    if(c!=cc)
    {
        f=0;
        ff=0,fff=0,ffff=0;
        cout<<f<<ff<<fff<<ffff;
        return 0;
    }
    if(ss[0]!=s[0] || s[1]!=ss[1])
    {
        ff=0;
        fff=0,ffff=0;
        cout<<f<<ff<<fff<<ffff;
        return 0;
    }
    if(((s[2]=='A'||s[2]=='B'||s[2]=='C') && (ss[2]=='A' || ss[2]=='B' || ss[2]=='C')) || (s[2]=='D'||s[2]=='F') && (ss[2]=='D' || ss[2]=='F'))
    {
        fff=1;
    }
    else
    {
        fff=0;
        ffff=0;
        cout<<f<<ff<<fff<<ffff;
        return 0;
    }
    if(ss[2]==s[2]+1 || s[2]==ss[2]+1)
    {
        ffff=1;
    }
    else ffff=0;
    cout<<f<<ff<<fff<<ffff;
    freopen("travel.out","w",stdout);
    return 0;
}
