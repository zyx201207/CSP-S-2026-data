#include <bits/stdc++.h>
using namespace std;
int x,r;
string xs,rs;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>xs>>r>>rs;
    if(x==r)
    {
        cout<<1;
        if(xs[0]==rs[0] && xs[1]==rs[1])
        {
            cout<<1;
            if((xs[2]<='C' && rs[2]<='C') || (xs[2]>'C' && rs[2]>'C'))
            {
                cout<<1;
                if(xs[2]-rs[2]==1 || xs[2]-rs[2]==-1)
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            else
            {
                cout<<00;
            }
        }
        else
        {
            cout<<000;
        }
    }
    else
    {
        cout<<0000;
    }
}
