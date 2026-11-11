#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"

string r1,r2,x1,x2;
int hi,li,hj,lj;
int n,m;
string a[10][20]={
"01F","02F","03F","04F","05F","06F","07F","08F","09F","10F","11F","12F","13F","14F","15F","16F","17F","18F",
"01D","02D","03D","04D","05D","06D","07D","08D","09D","10D","11D","12D","13D","14D","15D","16D","17D","18D",
"01C","02C","03C","04C","05C","06C","07C","08C","09C","10C","11C","12C","13C","14C","15C","16C","17C","18C",
"01B","02B","03B","04B","05B","06B","07B","08B","09B","10B","11B","12B","13B","14B","15B","16B","17B","18B",
"01A","02A","03A","04A","05A","06A","07A","08A","09A","10A","11A","12A","13A","14A","15A","16A","17A","18A"};
int main()
{
    freopen("travle.in","r",stdin);
    freopen("travle.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;
    for(int i=1;i<=5;++i){
        for(int j=1;j<=18;++j){
            if(r2==a[i][j]){
                hi=i;
                hj=j;
            }
            if(x2==a[i][j]){
                li=i;
                lj=j;
            }
        }
    }
    bool flag=(r1==x1);
    if(!flag){
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(flag&&hj!=lj){
        cout<<1<<0<<0<<0;
        return 0;
    }
    if(flag&&hj==lj&&(hi>=3&&li<=2||hi<=2&&li>=3)){
        cout<<1<<1<<0<<0;
        return 0;
    }
    if(flag&&hj==lj&&(hi>=3&&li>=3)||(hi<=2&&li<=2)){
        cout<<1<<1<<1<<0;
        return 0;
    }
    if(abs(hi-li)==1)cout<<1<<1<<1<<1;
    return 0;
}
