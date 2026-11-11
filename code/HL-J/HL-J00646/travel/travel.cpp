#include<bits/stdc++.h>
using namespace std;
string r,x,rr,xx;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r>>rr>>x>>xx;
    if(r==x)
        cout<<1;
    else
    {
        cout<<0<<0<<0<<0;
        return 0;
    }

    if(rr[0]==xx[0]&&rr[1]==xx[1])
    {
        cout<<1;
        if(rr[2]=='A'||rr[2]=='B'||rr[2]=='C')
        {
            if(xx[2]=='A'||xx[2]=='B'||xx[2]=='C')
            {
                cout<<1;
                if(rr[2]-1==xx[2]||rr[2]+1==xx[2])
                    cout<<1;
                else
                    cout<<0;
            }

            else
                cout<<0<<0;
        }
        else
        {
            if(xx[2]=='F'||xx[2]=='D')
            {
                cout<<1<<1;
            }
            else
                cout<<0<<0;
        }
    }
    else
        cout<<0<<0<<0;

    return 0;
}
