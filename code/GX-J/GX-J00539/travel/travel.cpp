#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3)
    {
        cout<<"1";
        if(c2[0]==c4[0] && c2[1]==c4[1])
        {
            cout<<"1";
            if(c2[2]>='A' && c4[2]<='C' || c2[2]>='D' && c4[2]<='F')
            {
                cout<<"1";
                if(c2[2]=='A' && c4[2]=='B' || c4[2]=='A' && c2[2]=='B' || c2[2]=='B' && c4[2]=='C' || c4[2]=='B' && c2[2]=='C' || c2[2]=='D' && c4[2]=='F' || c4[2]=='D' && c2[2]=='F')cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    //cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4;
    return 0;
}
