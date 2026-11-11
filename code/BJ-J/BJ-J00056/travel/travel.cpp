#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
string b1,d1;
int main()
{
     freopen("travel.in","r",stdin);
     freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    b1=b[0]+b[1];
    d1=d[0]+d[1];
    if(a==c)
    {
        cout<<"1";
        if(b1==d1)
        {
            cout<<"1";
            if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))
            {
                cout<<"1";
                if(b[2]==d[2]+1||b[2]==d[2]-1)
                {
                    cout<<"1";
                }
                else
                    cout<<"0";
            }
            else
                cout<<"00";
        }
        else
            cout<<"000";

    }
    else
        cout<<"0000";
    return 0;
}
