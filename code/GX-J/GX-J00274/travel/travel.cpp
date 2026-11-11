#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c) cout<<1;
    else cout<<0;
    if(a==b&&'d'-'b'==1||'d'-'b'==2||'d'-'b'==3||'d'-'b'==4) cout<<1;
    else cout<<0;
    if('d'-'b'==2||'d'-'b'==1||'d'-'b'==3) cout<<1;
    else cout<<0;
    if('d'-'b'==2) cout<<1;
    else cout<<0;
    return 0;
}
