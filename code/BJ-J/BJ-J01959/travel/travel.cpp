#include <bits/stdc++.h>
using namespace std;
string rc,rz,xc,xz;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rc>>rz>>xc>>xz;
    bool f=0;
    for (int i=0;i<2;i++)
    {
        if (rc[i]!=xc[i])
        {
            f=1;
            break;
        }
    }
    if (f==1)
    {
        cout<<"0000";
    }
    else
    {
        cout<<"1";
        f=0;
        for (int i=0;i<2;i++)
        {
            if (rz[i]!=xz[i])
            {
                f=1;
                break;
            }
        }
        if (f==1)
        {
            cout<<"000";
        }
        else
        {
            cout<<"1";
            f=0;
            if (rz[2]<='C'&&xz[2]<='C'||rz[2]>='D'&&xz[2]>='D')
            {
                f=0;
            }
            else
            {
                f=1;
            }
            if (f==1)
            {
                cout<<"00";
            }
            else
            {
                cout<<"1";
                f=0;
                if (rz[2]=='A'&&xz[2]=='B'||rz[2]=='B'&&xz[2]=='A'||rz[2]=='B'&&xz[2]=='C'||rz[2]=='C'&&xz[2]=='B'||rz[2]=='D'&&xz[2]=='F'||rz[2]=='F'&&xz[2]=='D')
                {
                    f=0;
                }
                else
                {
                    f=1;
                }
                if (f==1)
                {
                    cout<<"0";
                }
                else
                {
                    cout<<"1";
                }
            }
        }
    }
    return 0;
}
