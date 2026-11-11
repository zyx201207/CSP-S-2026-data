#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,C,S;
    cin>>c>>s>>C>>S;
    if(c==C)
    {
        cout<<'1';
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(s[0]==S[0]&&s[1]==S[1])
    {
        cout<<'1';
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(s[2]<='C'&&S[2]<='C')
    {
        cout<<'1';
    }
    else if(s[2]>='F'&&S[2]>='F')
    {
        cout<<'1';
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(s[2]==S[2]+1 || s[2]==S[2]-1)
    {
        cout<<'1';
    }
    else
    {
        cout<<'0';
        return 0;
    }
    return 0;

}
