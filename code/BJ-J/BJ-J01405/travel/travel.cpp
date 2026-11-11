#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)
    {
        cout<<1;
        if(s2[0]==s4[0]&&s2[1]==s4[1])
        {
            cout<<1;
            int l1=0,l2=0;
            if(s2[2]>'C')  l1 = 1;
            if(s4[2]>'C')  l2 = 1;
            if(l1==l2)
            {
                cout<<1;
                if(char(s2[2]+1)==s4[2]||char(s2[2]-1)==s4[2])
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            else
                cout<<0;
                cout<<0;
        }
        else
        {
            cout<<0;
            cout<<0;
            cout<<0;
        }
    }
    else
    {
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
    }

    return 0;
}
