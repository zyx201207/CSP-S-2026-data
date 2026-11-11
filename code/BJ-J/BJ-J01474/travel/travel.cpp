//T1
#include<bits/stdc++.h>
using namespace std;


int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string rc,rz,xc,xz;
    cin>>rc>>rz>>xc>>xz;
    if(rc==xc)
    {
        cout<<"1";
        if(rz[0]==xz[0] && rz[1]==xz[1])
        {
            cout<<"1";
            if(rz[2]=='A')
            {
                if(xz[2]=='B') cout<<"11";
                else if(xz[2]=='C') cout<<"10";
                else cout<<"00";
            }
            else if(rz[2]=='B')
            {
                if(xz[2]=='A' || xz[2]=='C') cout<<"11";
                else cout<<"00";
            }
            else if(rz[2]=='C')
            {
                if(xz[2]=='B') cout<<"11";
                else if(xz[2]=='A') cout<<"10";
                else cout<<"00";
            }
            else if(rz[2]=='D')
            {
                if(xz[2]=='E') cout<<"11";
                else cout<<"00";
            }
            else
            {
                if(xz[2]=='D') cout<<"11";
                else cout<<"00";
            }
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}