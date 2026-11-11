#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool ok=false;
    if(c1==c2)
        ok=true;
    if(s1[0]==s2[0]&&s1[1]==s2[1])
        ok=true;

    if(ok)
        cout<<'1';
    else
        cout<<'0';
    return 0;
}

