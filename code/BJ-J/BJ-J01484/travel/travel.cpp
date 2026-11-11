#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
        if(s1.substr(0,2)==s2.substr(0,2))
        {
            cout<<"1";
            if(s1[2]=='A')
            {
                if(s2[2]=='B'||s2[2]=='C')
                {
                    cout<<"1";
                    if(s2[2]=='B')
                    {
                        cout<<"1";
                    }
                    else cout<<"0";
                }
                else cout<<"00";
            }
            if(s1[2]=='B')
            {
                if(s2[2]=='A'||s2[2]=='C')
                {
                    cout<<"11";
                }
                else cout<<"00";
            }
            if(s1[2]=='C')
            {
                if(s2[2]=='B'||s2[2]=='A')
                {
                    cout<<"1";
                    if(s2[2]=='B')
                    {
                        cout<<"1";
                    }
                    else cout<<"0";
                }
                else cout<<"00";
            }
            if(s1[2]=='D')
            {
                if(s2[2]=='F')
                {
                    cout<<"11";
                }
                else cout<<"00";
            }
            if(s1[2]=='F')
            {
                if(s2[2]=='D')
                {
                    cout<<"11";
                }
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
