#include <bits/stdc++.h>
using namespace std;
int main()
{

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool cs1=1,cs2=1,cs3=1;
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cs1=0;
        cs2=0;
        cs3=0;
        cout<<0;
    }


    if(cs1)
    {
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {

            cout<<1;
        }
        else
        {
            cs2=0;
            cs3=0;
            cout<<0;
        }


    }
    else cout<<0;


    if(cs2)
    {
        if(s1[2]<='c'&&s2[2]>='D'||s2[2]<='c'&&s1[2]>='D')
        {
            cs3=0;

            cout<<0;
        }
        else
        {
            cout<<1;
        }

    }
    else cout<<0;



    if(cs3)
    {
        if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'||s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B')
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }

    }
    else cout<<0;

    return 0;
}
