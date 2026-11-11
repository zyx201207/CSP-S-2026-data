#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int rx,xx,ans=0;
    string rw,xw,rwh,xwh;
    cin>>rx>>rw>>xx>>xw;
    bool f1=false,f2=false,f3=false,f4=false;
    if(rx==xx) f1=true;
    cout<<f1;
    for(int i=0;i<2;i++){
        rwh+=rw[i];
        xwh+=xw[i];
    }
    if((xwh==rwh) && f1== true) f2=true;
    cout<<f2;
    char rz=rw[2],xz=xw[2];
    int fr=0,fx=0;
    if(rz<='C' && rz>='A') fr=1;
    else if(rz<='F' && rz>='D') fr=2;
    if(xz<='C' && xz>='A') fx=1;
    else if(xz<='F' && xz>='D') fr=2;
    if(fr==fx && f2==true && f1==true) f3=true;
    cout<<f3;
    char rz2=char(rz-1),rz1=char(rz+1);
    cout<<' '<<rz1<<' '<<rz2<<' '<<xz<<' ';
    if((xz==rz1 || xz==rz2) && f3==true && f2==true && f1==true) f4=true;
    cout<<f4;
    return 0;
}
