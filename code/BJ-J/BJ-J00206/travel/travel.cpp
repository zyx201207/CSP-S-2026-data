#include<bits/stdc++.h>
using namespace std;

signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x,xx,y,yy;
    cin>>x>>xx>>y>>yy;
    if(x==y) cout<<1;
    else cout<<0;
    if(x==y && xx[0]==yy[0] && xx[1]==yy[1]) cout<<1;
    else cout<<0;
    if(x==y && xx[0]==yy[0] && xx[1]==yy[1] && xx[2]<='C' && yy[2]<='C') cout<<1;
    else if(x==y && xx[0]==yy[0] && xx[1]==yy[1] && xx[2]>='D' && yy[2]>='D') cout<<1;
    else cout<<0;
    if(x==y && xx[0]==yy[0] && xx[1]==yy[1] && xx[2]<='C' && yy[2]<='C' && abs(int(xx[2])-int(yy[2]))==1) cout<<1;
    else if(x==y && xx[0]==yy[0] && xx[1]==yy[1] && xx[2]>='D' && yy[2]>='D'&& abs(int(xx[2])-int(yy[2]))==1) cout<<1;
    else cout<<0;
    return 0;
}
