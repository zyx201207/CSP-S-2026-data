#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a1,a2,b1,b2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1)
    {
        cout<<1;
        if(b2[0]==a2[0]&&b2[1]==a2[1])
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
        if((a2[2]=='D'||a2[2]=='F')&&(b2[2]=='D'||b2[2]=='F'))
        {
            cout<<11;
            if(abs((ll)(a2[2]-b2[2]))==1&&a2[2]!='D'&&b2[2]!='D')
            {
                cout<<11;
            }
            else
            {
                if(a2[2]!='D'&&a2[2]!='F'&&b2[2]!='D'&&b2[2]!='F')
                {
                    cout<<10;
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
