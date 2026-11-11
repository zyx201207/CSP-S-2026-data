#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long a;
    string rc,rz,xc,xz;
    cin>>rc>>rz>>xc>>xz;
    if(rc==xc)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(rz[1]==xz[1]&&rz[2]==xz[2])
    {
        cout<<"1";
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(rz[3]=='A'||rz[3]=='B'||rz[3]=='C')
    {
        if(xz[3]=='A'||xz[3]=='B'||xz[3]=='C')
        {
            cout<<"1";
            a=1;
        }
    }
    else if(rz[3]=='D'||rz[3]=='F')
    {
        if(xz[3]=='D'||xz[3]=='F')
        {
            cout<<"1";
        }
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(a==1&&rz[3]=='A'&&xz[3]=='C'||a==1&&rz[3]=='C'&&xz[3]=='A')
    {
        cout<<"0";
        return 0;
    }
    cout<<"1";
    return 0;
}
