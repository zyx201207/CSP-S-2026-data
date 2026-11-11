#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    char a,b;
    cin>>c1>>s1>>a>>c2>>s2>>b;
    if(c1!=c2)
    {
        cout<<"0000";
    }
    else
    {
        cout<<"1";
        if(s1!=s2)
        {
            cout<<"000";
        }
        else
        {
            cout<<"1";
            if(a=='A')
            {
                if(b=='B' || b=='C')
                {
                    cout<<"1";
                    if(b=='B')
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
            else if(a=='B')
            {
                if(b=='A' || b=='C')
                {
                    cout<<"11";
                }
                else
                {
                    cout<<"00";
                }
            }
            else if(a=='C')
            {
                if(b=='B' || b=='A')
                {
                    cout<<"1";
                    if(b=='B')
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
            else if(a=='D')
            {
                if(b=='F')
                {
                    cout<<"11";
                }
                else
                {
                    cout<<"00";
                }
            }
            else
            {
                if(b=='D')
                {
                    cout<<"11";
                }
                else
                {
                    cout<<"00";
                }
            }
        }
    }
    return 0;
}
