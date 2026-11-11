#include<bits/stdc++.h>
using namespace std;
int main( )
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    for(int x=1;x<=18;i++)
    {
        for(int y=1;y<=5;y++)
        {
            if(s1[y]==s2[y])
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
        }
        }
        if(s1[y]<=3,s2[y]<=3||s1[y]<=2,s2[y]<=2)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
        if(s1==s2+1||s1=s2-1)
        {

            cout<<1;
        }
        else
        {
            cout<<0;
        }

    return 0;
}
