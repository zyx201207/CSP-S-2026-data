#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string w1,w2,c1,c2;
    cin>>c1>>w1>>c2>>w2;
    if(c1==c2)
    {
        cout<<'1';
    }
    else
    {
        cout<<'0';
    }
    if(w1[0]==w2[0] and w1[1]==w2[1])
    {
        cout<<'1';
    }
    else
    {
        cout<<'0';
    }


    if(w1[2]<='C' and w1[2]>='A')
    {
        if(w2[2]>='A' and w2[2]<='C')
        {
            cout<<'1';
        }
        else
        {
            cout<<'0';
        }
    }
    else if(w1[2]<='F' and w1[2]>='D')
    {
        if(w2[2]>='D' and w2[2]<='F')
        {
            cout<<'1';
        }
        else
        {
            cout<<'0';
        }
    }
    if(w1[2]=='F' and w2[2]=='D' or w1[2]=='A' and w2[2]=='B' or w1[2]=='B' and w2[2]=='A' or w1[2]=='B' and w2[2]=='C' or w1[2]=='C' and w2[2]=='B')
    {
        cout<<'1';
    }
    else
    {
        cout<<'0';

    }
    return 0;
}
