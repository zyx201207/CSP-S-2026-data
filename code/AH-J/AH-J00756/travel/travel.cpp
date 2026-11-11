#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
signed main(void)
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>c>>d;
    if(a!=c)cout<<"0000";
    else
    {
        cout<<"1";
        if(b[0]!=d[0] || b[1]!=d[1])cout<<"000";
        else
        {
            cout<<"1";
            if((b[2]=='A' || b[2]=='B' || b[2]=='C') && (d[2]=='A' || d[2]=='B' || d[2]=='C'))
            {
                cout<<"1";
                if(b[2]+1==d[2] || d[2]+1==b[2])cout<<"1";
                else cout<<"0";
            }
            else if((b[2]=='D' || b[2]=='F') && (d[2]=='D' || d[2]=='F'))cout<<"11";
            else cout<<"00";
        }
    }
    return 0;
}
