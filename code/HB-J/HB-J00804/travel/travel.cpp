#include <bits/stdc++.h>
using namespace std;
string sf,ss;
int cf,cs;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cf>>sf>>cs>>ss;
    if(cf!=cs)
        cout<<"0000";
    else
    {
        cout<<"1";
        if(sf[1]!=ss[1]||sf[0]!=ss[0])
            cout<<"000";
        else
            {
                cout<<"1";
                if((sf[2]=='D'&&ss[2]=='F')||(sf[2]=='F'&&ss[2]=='D'))
                    cout<<"11";
                else if((sf[2]>'C'&&ss[2]<='C')||(sf[2]<='C'&&ss[2]>'C'))
                    cout<<"00";
                else if(sf[2]=='B'||ss[2]=='B')
                    cout<<"11";
                else
                    cout<<"10";
            }
    }
    return 0;
}
