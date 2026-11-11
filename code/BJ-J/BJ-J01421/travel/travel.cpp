#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int s1num,s2num,p1,p2;
bool f;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else cout<<0;

    if(s1[0]=='0') s1num=(s1[1]-'0');
    else s1num=(s1[0]-'0')*10+(s1[1]-'0');
    if(s2[0]=='0') s2num=(s2[1]-'0');
    else s2num=(s2[0]-'0')*10+(s2[1]-'0');

    if(c1==c2 && s1num==s2num) cout<<1;
    else cout<<0;

    if(s1[2]=='A') p1=1;
    else if(s1[2]=='B') p1=2;
    else if(s1[2]=='C') p1=3;
    else if(s1[2]=='D') p1=4;
    else if(s1[2]=='F') p1=5;

    if(s2[2]=='A') p2=1;
    else if(s2[2]=='B') p2=2;
    else if(s2[2]=='C') p2=3;
    else if(s2[2]=='D') p2=4;
    else if(s2[2]=='F') p2=5;

    if((p1<=3 && p2<=3) || (p1>3 && p2>3)) f=1;

    if(c1==c2 && s1num==s2num && f) cout<<1;
    else cout<<0;

    if(c1==c2 && s1num==s2num && f && (abs(p1-p2))==1)
        cout<<1;
    else
        cout<<0;
}