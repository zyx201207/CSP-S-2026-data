#include<bits/stdc++.h>
using namespace std;
bool a,b,c,d;
string rc,rs,xc,xs;
char XS,RS;
int main(){
    ios::sync_with_stdio(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>rc>>rs>>xc>>xs;
    if(rc==xc) a=1;
    RS=rs[2];
    string t="";
    t+=rs[0];
    t+=rs[1];
    rs=t;
    XS=xs[2];
    t="";
    t+=xs[0];
    t+=xs[1];
    xs=t;
    if(a==1&&xs==rs) b=1;
    if(a==1&&b==1){
        if(RS>='D'&&RS<='F'&&XS>='D'&&XS<='F') c=1;
        else if(RS>='A'&&RS<='C'&&XS>='A'&&XS<='C') c=1;
    }
    if(c==1&&max(RS,XS)-min(RS,XS)==1) d=1;
    cout<<a<<b<<c<<d;
    return 0;
}
