#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string c1,s1,c2,s2;
    bool c=0,d=0;
    cin>>c1>>s1>>c2>>s2;
    if(abs(s1[2]-s2[2])=='B'-'A'&&s1[2]+s2[2]!='C'+'D'||s1[2]+s2[2]=='D'+'F')
        c=1;
    if(s1[2]+s2[2]=='A'+'B'||s1[2]+s2[2]=='C'+'B'||s1[2]+s2[2]=='C'+'A'||s1[2]+s2[2]=='D'+'F')
        d=1;
    if(c1==c2)
    {
        cout<<1;
    }
    else {
        cout<<0;
    }
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
    {
        cout<<1;
    }
    else {
        cout<<0;
    }
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&d==1)
    {
        cout<<1;
    }
    else {
        cout<<0;
    }
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&c==1&&d==1)
    {
        cout<<1;
    }
    else {
        cout<<0;
    }
    return 0;
}
