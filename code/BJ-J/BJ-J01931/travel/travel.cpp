#include<bits/stdc++.h>
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
        string x=s1.substr(0,2);
        string y=s2.substr(0,2);
        if(x==y)
        {
            cout<<"1";
            char a=s1[2];
            char b=s2[2];
            if(a=='A')
            {
                if(b=='B')
                {
                    cout<<11;
                }
                else if(b=='C')
                {
                    cout<<10;
                }
                else if(b=='D'||b=='E')
                {
                    cout<<"00";
                }
            }
            else if(a=='B')
            {
                if(b=='A'||b=='C')
                {
                    cout<<11;
                }
                else if(b=='D'||b=='E')
                {
                    cout<<"00";
                }
            }
            else if(a=='C')
            {
                if(b=='B')
                {
                    cout<<11;
                }
                else if(b=='A')
                {
                    cout<<10;
                }
                else if(b=='D'||b=='E')
                {
                    cout<<"00";
                }
            }
            else  if(a=='D')
            {
                if(b=='E')
                {
                    cout<<11;
                }
                else if(b=='A'||b=='B'||b=='C')
                {
                    cout<<"00";
                }
            }
            else
            {
                if(b=='D')
                {
                    cout<<11;
                }
                else if(b=='A'||b=='B'||b=='C')
                {
                    cout<<"00";
                }
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
