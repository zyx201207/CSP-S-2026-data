#include<bits/stdc++.h>
using namespace std;
string s[4];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s[0]>>s[1]>>s[2]>>s[3];
    if(s[0]==s[2])
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    char sx[3]={s[1][0],s[1][1]},sy[3]={s[3][0],s[3][1]};
    if(sx[1]==sy[1]&&sx[0]==sy[0])
    {
        cout<<"1";
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(s[1][2]<='C'&&s[3][2]<='C'||s[1][2]>'C'&&s[3][2]>'C')
    {
        cout<<"1";
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(s[1][2]<='C'&&s[3][2]<='C')
    {
        cout<<(s[1][2]=='B'||s[3][2]=='B'?"1":"0");
    }
    else
    {
        cout<<"1";
    }

    return 0;
}
