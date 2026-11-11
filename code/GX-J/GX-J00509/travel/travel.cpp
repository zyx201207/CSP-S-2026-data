#include<bits/stdc++.h>
using namespace std;
string s1[2],s2[2];
int main()
{
    freopen("travel.in";"r".stdin)
    freopen("travel.out";"w".stdout)
    int c1,c2,;
    cin>>c1;
    for(int i=0;i<2;i++)
    {
        cin>>s1[i];
    }
    cin>>c2
    for(int i=0;i<2;i++)
    {
        cin>>s2[i];
    }
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<0000;
    }
    if(s1[0]==s2[0])
    {
        cout>>1;
        if(s1[1]==A || s1[1]==B || s1[1]==C)
        {
            if(s2[1]==A || s2[1]==B || s2[1]==C)
            {
            cout<<1;
            }
        }
        else if(s2[1]==D || s2[1]==E)
        {
            cout<<1;
        }
        else
        {
            cout<<00;
        }
    }
    else
    {
        cout<<000;
    }
    if(s1[1]-s2[1]==1 || s2[1]-s1[1]==1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }

    return 0;
}
