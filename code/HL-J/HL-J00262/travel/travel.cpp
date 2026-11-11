#include<bits/stdc++.h>
using namespace std;
int r1,x1,a,b,c,d;
int rr,xx;
int rpai,xpai;
string rzuo,xzuo;
char rzuod,xzuod;
string zuo;
string r2,x2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;
    for(int i=0;i<=1;i++){
        rpai=rpai*10+(r2[i]-'0');
        xpai=xpai*10+(x2[i]-'0');

    }

    rzuo=r2[2];
    xzuo=x2[2];
    rzuod=r2[2];
    xzuod=x2[2];
    if(r1==x1){
        a=1;
        if(rpai==xpai){
            b=1;
            if(rzuod<='C'&&xzuod<='C'){
                rr=1;
            }
            if(rzuod>='D'&&xzuod>='D'){
                xx=1;
            }

            if(rr==1||xx==1){
                c=1;
                zuo=rzuo+xzuo;
                if(zuo=="AB"||zuo=="BA"||zuo=="CB"||zuo=="BC"||zuo=="FD"||zuo=="DF"){
                    d=1;
                }
                else{
                    d=0;
                }
            }
            else{
                c=0;
                d=0;
            }

        }

        else{
            b=0;
            c=0;
            d=0;
        }
    }
    else{
        a=0;
        b=0;
        c=0;
        d=0;
    }
    cout<<a<<b<<c<<d;
    return 0;
}

