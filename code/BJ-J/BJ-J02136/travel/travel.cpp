#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
bool chx=0,p=0,pc=0,xl=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rc>>rs>>xc>>xs;
    if(rc==xc) chx=1;
    if(chx&&(rs[0]==xs[0]&&rs[1]==xs[1])) p=1;
    if(chx&&p&&((rs[2]<='C'&&xs[2]<='C')||(rs[2]>'C'&&xs[2]>'C'))) pc=1;
    if(chx&&p&&pc&&((rs[2]-xs[2]==1)||(rs[2]-xs[2]==-1))) xl=1;
    cout<<chx<<p<<pc<<xl;
    return 0;
}
