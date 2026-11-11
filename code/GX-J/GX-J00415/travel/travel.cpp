#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    frepoen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(a2[1]==b2[1]&&a2[2]==b2[2])
    {
        cout<<1;
        if(a2[3]=='A'||a2[3]=='B'||a2[3]=='C')
        {
            if(b2[3]=='A'||b2[3]=='B'||b2[3]=='C')
            {
                cout<<1;
                if(a2[3]+1==b2[3]||b2[3]+1==a2[3])
                    cout<<1;
                else
                    cout<<0;
            }
        }
        else if(a2[3]=='D'||a2[3]=='F')
            if(b2[3]=='D'||b2[3]=='F')
            {
                cout<<1<<1;

            }
        else
            cout<<0;
    }
    else
    {
        cout<<0<<0<<0;
    }

    return 0;
}
