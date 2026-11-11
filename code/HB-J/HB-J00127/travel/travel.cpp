#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool pd1(char x,char y)
{
    if(x>='A'&&x<='C'&&y>='A'&&y<='C')
    {
        return 1;
    }
    else if(x>='D'&&x<='F'&&y>='D'&&y<='F')
    {
        return 1;
    }
    return 0;
}
bool pd2(char x,char y)
{
    if(x>='A'&&x<='C'&&y>='A'&&y<='C')
    {
        return abs(x-y)==1;
    }
    else if(x>='D'&&x<='F'&&y>='D'&&y<='F')
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<"1";
            if(pd1(s1[2],s2[2]))
            {
                cout<<"1";
                if(pd2(s1[2],s2[2]))
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
