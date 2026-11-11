#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
signed main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c)cout<<1;
    else{cout<<"0000";return 0;}
    if(b[0]==d[0]&&b[1]==d[1])cout<<1;
    else{cout<<"000";return 0;}
    if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))cout<<1;
    else{cout<<"00";return 0;}
    if(b[2]=='B'||d[2]=='B'||b[2]=='E'||d[2]=='E')cout<<1;
    else cout<<0;
    return 0;
}
