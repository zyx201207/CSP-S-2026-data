#include<bits/stdc++.h>
using namespace std;
string s_1,s_2;
string c_1,c_2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s_1>>c_1>>s_2>>c_2;
    if(s_1==s_2)
    {
        cout<<"1";
        if(c_1[0]==c_2[0] && c_1[1]==c_2[1])
        {
            cout<<"1";
            if(c_1[2]=='A')
            {
                if(c_2[2]=='B') cout<<"11";
                else if(c_2[2]=='C') cout<<"10";
                else cout<<"00";
            }
            else if(c_1[2]=='B')
            {
                if(c_2[2]=='A' || c_2[2]=='C') cout<<"11";
                else cout<<"00";
            }
            else if(c_1[2]=='C')
            {
                if(c_2[2]=='B') cout<<"11";
                else if(c_2[2]=='A') cout<<"10";
                else cout<<"00";
            }
            else if(c_1[2]=='D')
            {
                if(c_2[2]=='F') cout<<"11";
                else cout<<"00";
            }
            else
            {
                if(c_2[2]=='D') cout<<"11";
                else cout<<"00";
            }
        }
        else cout<<"000";
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
