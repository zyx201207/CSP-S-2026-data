#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    bool e=0,f=0;
    if(b[2]=='A'||b[2]=='B'||b[2]=='C')e=1;
    if(d[2]=='A'||d[2]=='B'||d[2]=='C')f=1;
    if(a==c)cout<<1;
    else cout<<0;
    if(a==c&&b[0]==d[0]&&b[1]==d[1])cout<<1;
    else cout<<0;
    if(a==c&&b[0]==d[0]&&b[1]==d[1]&&e==f)cout<<1;
    else cout<<0;
    if(a==c&&b[0]==d[0]&&b[1]==d[1]&&e==f&&(!(b[2]=='C'&&d[2]=='A'||b[2]=='A'&&d[2]=='C')))cout<<1;
    else cout<<0;
    return 0;
}