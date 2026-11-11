#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool x1=false,x2=false,x3=true,x4=true;
    if(c1[1]==c2[1]&&c1[0]==c2[0])
    {
        x1=true;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            x2=true;
            if(s2[2]==s1[2]+'1'||s2[2]==s1[2]-'1')
                x3=false;
            else if(s2[2]==s1[2]+'2'||s2[2]==s1[2]-'2')
                x3=false;
        }
    }
    if(x2)
    {
        if(s2[2]==s1[2]+'1')
            x4=false;
        else if(s2[2]==s1[2]-'1')
            x4=false;
    }
    if(x1)
        cout<<"1";
    else    cout<<"0";
    if(x2)
        cout<<"1";
    else    cout<<"0";
    if(x3)
        cout<<"1";
    else    cout<<"0";
    if(x4)
        cout<<"1";
    else    cout<<"0";
    return 0;
}
