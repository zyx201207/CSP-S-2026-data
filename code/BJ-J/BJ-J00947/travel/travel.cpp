#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a=0,b=0;
    if(s1[2]=='A') a=1;
    if(s1[2]=='B') a=2;
    if(s1[2]=='C') a=3;
    if(s1[2]=='D') a=5;
    if(s1[2]=='F') a=6;
    if(s2[2]=='A') b=1;
    if(s2[2]=='B') b=2;
    if(s2[2]=='C') b=3;
    if(s2[2]=='D') b=5;
    if(s2[2]=='F') b=6;
    if(c1!=c2)
    {
        cout<<"0000";
    }
    else
    {
        cout<<1;
        if((s1[0]==s2[0])&&(s1[1]==s2[1]))
        {
            cout<<1;
            if((a<=3&&b<=3)||(a>=5&&b>=5))
            {
                cout<<1;
                if(abs(a-b)==1) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    return 0;
}
