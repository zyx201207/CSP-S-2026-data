#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    string b,d;
    cin>>a>>b>>c>>d;
    int b1 = (b[0]-'0')*10+b[1]-'0',d1 = (d[0]-'0')*10+d[1]-'0';
    //cout<<b1<<' '<<d1;
    if(a == c) cout<<1;
    else cout<<0;
    if(a == c&&b1 == d1) cout<<1;
    else cout<<0;
    if(a == c&&((b[2]<='C' && d[2]<='C') || (b[2]>'C' && d[2]>'C')) && b1 == d1) cout<<1;
    else cout<<0;
    if( a == c&&(b[2]-d[2] == 1 || b[2]-d[2] == -1) && !(b[2] == 'C' && d[2] == 'D') && !(b[2] == 'D' && d[2] == 'C') && b1 == d1) cout<<1;
    else cout<<0;
    return 0;
}
