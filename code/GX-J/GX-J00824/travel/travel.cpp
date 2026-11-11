#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long c1,c3;
    string c2,c4,a,b;
    char d,e;
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3)cout<<"1";
    else cout<<"0";
    a=c2[0]+c2[1];
    b=c4[0]+c4[1];
    if(c1==c3 and a==b)cout<<"1";
    else cout<<"0";
    d=c2[2];
    e=c4[2];
    if(c1==c3 and a==b and ((d>='D' and e>='D') or (d<='C' and e<='C')))cout<<"1";
    else cout<<"0";
    if(c1==c3 and a==b and ((d>='D' and e>='D') or (d<='C' and e<='C')) and (d+1==e or d-1==e))cout<<"1";
    else cout<<"0";
    return 0;
}
