#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
    cin>>s1>>c1>>s2>>c2;
    if(s1==s2)
    {
        cout<<1;
        if(c1[0]==c2[0]&&c1[1]==c2[1])
        {
            cout<<1;
            if(c1>c2)
            {
                swap(c1,c2);
            }
            if(c2[2]=='B')
            {
                cout<<11;
            }
            else if(c2[2]=='C')
            {
                if(c1[2]=='A')
                {
                    cout<<10;
                }
                else
                {
                    cout<<11;
                }
            }
            else if(c2[2]=='D')
            {
                cout<<"00";
            }
            else if(c2[2]=='F')
            {
                if(c1[2]=='D')
                {
                    cout<<11;
                }
                else
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
