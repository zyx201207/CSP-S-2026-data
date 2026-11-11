#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //print("%.nlf",n);
    string rx,xx,rw,xw;
    cin>>rx>>rw>>xx>>xw;
    if(rx==xx){
        cout<<"1";
        if(rw=="01A"||rw=="01B"||rw=="01C"||rw=="01D"||rw=="01E"||rw=="01F"){
            if(xw=="01A"||xw=="01B"||xw=="01C"||xw=="01D"||xw=="01E"||xw=="01F"){
                cout<<"1";
                if(rw=="01A"&&xw=="01B"){
                    cout<<"11";
                }
                else if(rw=="01B"&&xw=="01C"){
                    cout<<"11";
                }
                else if(rw=="01B"&&xw=="01A"){
                    cout<<"11";
                }
                else if(rw=="01C"&&xw=="01B"){
                    cout<<"11";
                }
                else if(rw=="01D"&&xw=="01E"){
                    cout<<"11";
                }
                else if(rw=="01E"&&xw=="01D"){
                    cout<<"11";
                }
                else if(rw=="01C"&&xw=="01A"){
                    cout<<"10";
                }
                else if(rw=="01A"&&xw=="01C"){
                    cout<<"10";
                }
                else cout<<"00";
            }
            else {
                cout<<"000";
            }
        }
        else if(rw=="02A"||rw=="02B"||rw=="02C"||rw=="02D"||rw=="02E"||rw=="02F"){
            if(xw=="02A"||xw=="02B"||xw=="02C"||xw=="02D"||xw=="02E"||xw=="02F"){
                cout<<"1";
                if(rw=="02A"&&xw=="02B"){
                    cout<<"11";
                }
                else if(rw=="02B"&&xw=="02C"){
                    cout<<"11";
                }
                else if(rw=="02B"&&xw=="02A"){
                    cout<<"11";
                }
                else if(rw=="02C"&&xw=="02B"){
                    cout<<"11";
                }
                else if(rw=="02D"&&xw=="02E"){
                    cout<<"11";
                }
                else if(rw=="02E"&&xw=="02D"){

                    cout<<"11";
                }
                else if(rw=="02C"&&xw=="02A"){
                    cout<<"10";
                }
                else if(rw=="02A"&&xw=="02C"){
                    cout<<"10";
                }
                else cout<<"00";
            }
            else {
                cout<<"000";
            }
        }
        else if(rw=="03A"||rw=="03B"||rw=="03C"||rw=="03D"||rw=="03E"||rw=="03F"){
            if(xw=="03A"||xw=="03B"||xw=="03C"||xw=="03D"||xw=="03E"||xw=="03F"){
                cout<<"1";
                if(rw=="03A"&&xw=="03B"){
                    cout<<"11";
                }
                else if(rw=="03B"&&xw=="03C"){
                    cout<<"11";
                }
                else if(rw=="03B"&&xw=="03A"){
                    cout<<"11";
                }
                else if(rw=="03C"&&xw=="03B"){
                    cout<<"11";
                }
                else if(rw=="03D"&&xw=="03E"){
                    cout<<"11";
                }
                else if(rw=="02E"&&xw=="02D"){
                    cout<<"11";
                }
                else if(rw=="03C"&&xw=="03A"){
                    cout<<"10";
                }
                else if(rw=="03A"&&xw=="03C"){
                    cout<<"10";
                }
                else cout<<"00";
            }
            else {
                cout<<"000";
            }
        }
        else if(rw=="04A"||rw=="04B"||rw=="04C"||rw=="04D"||rw=="04E"||rw=="04F"){
            if(xw=="04A"||xw=="04B"||xw=="04C"||xw=="04D"||xw=="04E"||xw=="04F"){
                cout<<"1";
                if(rw=="04A"&&xw=="04B"){
                    cout<<"11";
                }
                else if(rw=="04B"&&xw=="04C"){
                    cout<<"11";
                }
                else if(rw=="04B"&&xw=="04A"){
                    cout<<"11";
                }
                else if(rw=="04C"&&xw=="04B"){
                    cout<<"11";
                }
                else if(rw=="04D"&&xw=="04E"){
                    cout<<"11";
                }
                else if(rw=="04E"&&xw=="04D"){
                    cout<<"11";
                }
                else if(rw=="04C"&&xw=="04A"){
                    cout<<"10";
                }
                else if(rw=="04A"&&xw=="04C"){
                    cout<<"10";
                }
                else cout<<"00";
            }
            else {
                cout<<"000";
            }
        }
        else if(rw=="05A"||rw=="05B"||rw=="05C"||rw=="05D"||rw=="05E"||rw=="05F"){
            if(xw=="05A"||xw=="05B"||xw=="05C"||xw=="05D"||xw=="05E"||xw=="05F"){
                cout<<"1";
                if(rw=="05A"&&xw=="05B"){
                    cout<<"11";
                }
                else if(rw=="05B"&&xw=="05C"){
                    cout<<"11";
                }
                else if(rw=="05B"&&xw=="05A"){
                    cout<<"11";
                }
                else if(rw=="05C"&&xw=="05B"){
                    cout<<"11";
                }
                else if(rw=="05D"&&xw=="05E"){
                    cout<<"11";
                }
                else if(rw=="05E"&&xw=="05D"){
                    cout<<"11";
                }
                else if(rw=="05C"&&xw=="05A"){
                    cout<<"10";
                }
                else if(rw=="05A"&&xw=="05C"){
                    cout<<"10";
                }
                else cout<<"00";
            }
            else {
                cout<<"000";
            }
        }
        else if(rw=="06A"||rw=="06B"||rw=="06C"||rw=="06D"||rw=="06E"||rw=="06F"){
            if(xw=="06A"||xw=="06B"||xw=="06C"||xw=="06D"||xw=="06E"||xw=="06F"){
                cout<<"1";
                if(rw=="06A"&&xw=="06B"){
                    cout<<"11";
                }
                else if(rw=="06B"&&xw=="06C"){
                    cout<<"11";
                }
                else if(rw=="06B"&&xw=="06A"){
                    cout<<"11";
                }
                else if(rw=="06C"&&xw=="06B"){
                    cout<<"11";
                }
                else if(rw=="06D"&&xw=="06E"){
                    cout<<"11";
                }
                else if(rw=="06E"&&xw=="06D"){
                    cout<<"11";
                }
                else if(rw=="06C"&&xw=="06A"){
                    cout<<"10";
                }
                else if(rw=="06A"&&xw=="06C"){
                    cout<<"10";
                }
                else cout<<"00";
            }
            else {
                cout<<"000";
            }
        }
        else if(rw=="07A"||rw=="07B"||rw=="07C"||rw=="07D"||rw=="07E"||rw=="07F"){
            if( xw=="07A"||xw=="07B"||xw=="07C"||xw=="07D"||xw=="07E"||xw=="07F"){
                cout<<"1";
                if(     rw=="07A"&&xw=="07B"){
                    cout<<"11";
                }
                else if(rw=="07B"&&xw=="07C"){
                    cout<<"11";
                }
                else if(rw=="07B"&&xw=="07A"){
                    cout<<"11";
                }
                else if(rw=="07C"&&xw=="07B"){
                    cout<<"11";
                }
                else if(rw=="07D"&&xw=="07E"){
                    cout<<"11";
                }
                else if(rw=="07E"&&xw=="07D"){
                    cout<<"11";
                }
                else if(rw=="07C"&&xw=="07A"){
                    cout<<"10";
                }
                else if(rw=="07A"&&xw=="07C"){
                    cout<<"10";
                }
                else cout<<"00";
            }
            else {
                cout<<"000";
            }
        }
        else if(rw=="08A"||rw=="08B"||rw=="08C"||rw=="08D"||rw=="08E"||rw=="08F"){
            if( xw=="08A"||xw=="08B"||xw=="08C"||xw=="08D"||xw=="08E"||xw=="08F"){
                cout<<"1";
                if(     rw=="08A"&&xw=="08B"){
                    cout<<"11";
                }
                else if(rw=="08B"&&xw=="08C"){
                    cout<<"11";
                }
                else if(rw=="08B"&&xw=="08A"){
                    cout<<"11";
                }
                else if(rw=="08C"&&xw=="08B"){
                    cout<<"11";
                }
                else if(rw=="08D"&&xw=="08E"){
                    cout<<"11";
                }
                else if(rw=="08E"&&xw=="08D"){
                    cout<<"11";
                }
                else if(rw=="08C"&&xw=="08A"){
                    cout<<"10";
                }
                else if(rw=="08A"&&xw=="08C"){
                    cout<<"10";
                }
                else cout<<"00";
            }
            else {
                cout<<"000";
            }
        }
        else if(rw=="09A"||rw=="09B"||rw=="09C"||rw=="09D"||rw=="09E"||rw=="09F"){
            if( xw=="09A"||xw=="09B"||xw=="09C"||xw=="09D"||xw=="09E"||xw=="09F"){
                cout<<"1";
                if(     rw=="09A"&&xw=="09B"){
                    cout<<"11";
                }
                else if(rw=="09B"&&xw=="09C"){
                    cout<<"11";
                }
                else if(rw=="09B"&&xw=="09A"){
                    cout<<"11";
                }
                else if(rw=="09C"&&xw=="09B"){
                    cout<<"11";
                }
                else if(rw=="09D"&&xw=="09E"){
                    cout<<"11";
                }
                else if(rw=="09E"&&xw=="09D"){
                    cout<<"11";
                }
                else if(rw=="09C"&&xw=="09A"){
                    cout<<"10";
                }
                else if(rw=="09A"&&xw=="09C"){
                    cout<<"10";
                }
                else cout<<"00";
            }
            else {
                cout<<"000";
            }
        }
        else if(rw=="10A"||rw=="10B"||rw=="10C"||rw=="10D"||rw=="10E"||rw=="10F"){
            if(xw=="10A"||xw=="10B"||xw=="10C"||xw=="10D"||xw=="10E"||xw=="10F"){
                cout<<"1";
                if(rw=="10A"&&     xw=="10B"){
                    cout<<"11";
                }
                else if(rw=="10B"&&xw=="10C"){
                    cout<<"11";
                }
                else if(rw=="10B"&&xw=="10A"){
                    cout<<"11";
                }
                else if(rw=="10C"&&xw=="10B"){
                    cout<<"11";
                }
                else if(rw=="10D"&&xw=="10E"){
                    cout<<"11";
                }
                else if(rw=="10E"&&xw=="10D"){
                    cout<<"11";
                }
                else if(rw=="10C"&&xw=="10A"){
                    cout<<"10";
                }
                else if(rw=="10A"&&xw=="10C"){
                    cout<<"10";
                }
                else cout<<"00";
            }
            else {
                cout<<"000";
            }
        }
        else if(rw=="11A"||rw=="11B"||rw=="11C"||rw=="11D"||rw=="11E"||rw=="11F"){
            if(xw=="11A"||xw=="11B"||xw=="11C"||xw=="11D"||xw=="11E"||xw=="11F"){
                cout<<"1";
                if(rw=="11A"&&xw=="11B"){
                    cout<<"11";
                }
                else if(rw=="11B"&&xw=="11C"){
                    cout<<"11";
                }
                else if(rw=="11B"&&xw=="11A"){
                    cout<<"11";
                }
                else if(rw=="11C"&&xw=="11B"){
                    cout<<"11";
                }
                else if(rw=="11D"&&xw=="11E"){
                    cout<<"11";
                }
                else if(rw=="11E"&&xw=="11D"){
                    cout<<"11";
                }
                else if(rw=="11C"&&xw=="11A"){
                    cout<<"10";
                }
                else if(rw=="11A"&&xw=="11C"){
                    cout<<"10";
                }
                else cout<<"00";
            }
            else {
                cout<<"000";
            }
        }
        else if(rw=="12A"||rw=="12B"||rw=="12C"||rw=="12D"||rw=="12E"||rw=="12F"){
            if(xw=="12A"||xw=="12B"||xw=="12C"||xw=="12D"||xw=="12E"||xw=="12F"){
                cout<<"1";
                if(rw=="12A"&&xw=="12B"){
                    cout<<"11";
                }
                else if(rw=="12B"&&xw=="12C"){
                    cout<<"11";
                }
                else if(rw=="12B"&&xw=="12A"){
                    cout<<"11";
                }
                else if(rw=="12C"&&xw=="12B"){
                    cout<<"11";
                }
                else if(rw=="12D"&&xw=="12E"){
                    cout<<"11";
                }
                else if(rw=="12E"&&xw=="12D"){
                    cout<<"11";
                }
                else if(rw=="12C"&&xw=="12A"){
                    cout<<"10";
                }
                else if(rw=="12A"&&xw=="12C"){
                    cout<<"10";
                }
                else cout<<"00";
            }
            else {
                cout<<"000";
            }
        }
        else if(rw=="13A"||rw=="13B"||rw=="13C"||rw=="13D"||rw=="13E"||rw=="13F"){
            if(xw=="13A"||xw=="13B"||xw=="13C"||xw=="13D"||xw=="13E"||xw=="13F"){
                cout<<"1";
                if(rw=="13A"&&xw=="13B"){
                    cout<<"11";
                }
                else if(rw=="13B"&&xw=="13C"){
                    cout<<"11";
                }
                else if(rw=="13B"&&xw=="13A"){
                    cout<<"11";
                }
                else if(rw=="13C"&&xw=="13B"){
                    cout<<"11";
                }
                else if(rw=="13D"&&xw=="13E"){
                    cout<<"11";
                }
                else if(rw=="13E"&&xw=="13D"){
                    cout<<"11";
                }
                else if(rw=="13C"&&xw=="13A"){
                    cout<<"10";
                }
                else if(rw=="13A"&&xw=="13C"){
                    cout<<"10";
                }
                else cout<<"00";
            }
            else {
                cout<<"000";
            }
        }
        else if(rw=="14A"||rw=="14B"||rw=="14C"||rw=="14D"||rw=="14E"||rw=="14F"){
            if(xw=="14A"||xw=="14B"||xw=="14C"||xw=="14D"||xw=="14E"||xw=="14F"){
                cout<<"1";
                if(rw=="14A"&&xw=="14B"){
                    cout<<"11";
                }
                else if(rw=="14B"&&xw=="14C"){
                    cout<<"11";
                }
                else if(rw=="14B"&&xw=="14A"){
                    cout<<"11";
                }
                else if(rw=="14C"&&xw=="14B"){
                    cout<<"11";
                }
                else if(rw=="14D"&&xw=="14E"){
                    cout<<"11";
                }
                else if(rw=="14E"&&xw=="14D"){
                    cout<<"11";
                }
                else if(rw=="14C"&&xw=="14A"){
                    cout<<"10";
                }
                else if(rw=="14A"&&xw=="14C"){
                    cout<<"10";
                }
                else cout<<"00";
            }
            else {
                cout<<"000";
            }
        }
        else if(rw=="15A"||rw=="15B"||rw=="15C"||rw=="15D"||rw=="15E"||rw=="15F"){
            if(xw=="15A"||xw=="15B"||xw=="15C"||xw=="15D"||xw=="15E"||xw=="15F"){
                cout<<"1";
                if(rw=="15A"&&xw=="15B"){
                    cout<<"11";
                }
                else if(rw=="15B"&&xw=="15C"){
                    cout<<"11";
                }
                else if(rw=="15B"&&xw=="15A"){
                    cout<<"11";
                }
                else if(rw=="15C"&&xw=="15B"){
                    cout<<"11";
                }
                else if(rw=="15D"&&xw=="15E"){
                    cout<<"11";
                }
                else if(rw=="15E"&&xw=="15D"){
                    cout<<"11";
                }
                else if(rw=="15C"&&xw=="15A"){
                    cout<<"10";
                }
                else if(rw=="15A"&&xw=="15C"){
                    cout<<"10";
                }
                else cout<<"00";
            }
            else {
                cout<<"000";
            }
        }
        else if(rw=="16A"||rw=="16B"||rw=="16C"||rw=="16D"||rw=="16E"||rw=="16F"){
            if(xw=="16A"||xw=="16B"||xw=="16C"||xw=="16D"||xw=="16E"||xw=="16F"){
                cout<<"1";
                if(rw=="16A"&&xw=="16B"){
                    cout<<"11";
                }
                else if(rw=="16B"&&xw=="16C"){
                    cout<<"11";
                }
                else if(rw=="16B"&&xw=="16A"){
                    cout<<"11";
                }
                else if(rw=="16C"&&xw=="16B"){
                    cout<<"11";
                }
                else if(rw=="16D"&&xw=="16E"){
                    cout<<"11";
                }
                else if(rw=="16E"&&xw=="16D"){
                    cout<<"11";
                }
                else if(rw=="16C"&&xw=="16A"){
                    cout<<"10";
                }
                else if(rw=="16A"&&xw=="16C"){
                    cout<<"10";
                }
                else cout<<"00";
            }
            else {
                cout<<"000";
            }
        }
        else if(rw=="17A"||rw=="17B"||rw=="17C"||rw=="17D"||rw=="17E"||rw=="17F"){
            if(xw=="17A"||xw=="17B"||xw=="17C"||xw=="17D"||xw=="17E"||xw=="17F"){
                cout<<"1";
                if(rw=="17A"&&xw=="17B"){
                    cout<<"11";
                }
                else if(rw=="17B"&&xw=="17C"){
                    cout<<"11";
                }
                else if(rw=="17B"&&xw=="17A"){
                    cout<<"11";
                }
                else if(rw=="17C"&&xw=="17B"){
                    cout<<"11";
                }
                else if(rw=="17D"&&xw=="17E"){
                    cout<<"11";
                }
                else if(rw=="17E"&&xw=="17D"){
                    cout<<"11";
                }
                else if(rw=="17C"&&xw=="17A"){
                    cout<<"10";
                }
                else if(rw=="17A"&&xw=="17C"){
                    cout<<"10";
                }
                else cout<<"00";
            }
            else {
                cout<<"000";
            }
        }
        else if(rw=="18A"||rw=="18B"||rw=="18C"||rw=="18D"||rw=="18E"||rw=="18F"){
            if(xw=="18A"||xw=="18B"||xw=="18C"||xw=="18D"||xw=="18E"||xw=="18F"){
                cout<<"1";
                if(rw=="18A"&&xw=="18B"){
                    cout<<"11";
                }
                else if(rw=="18B"&&xw=="18C"){
                    cout<<"11";
                }
                else if(rw=="18B"&&xw=="18A"){
                    cout<<"11";
                }
                else if(rw=="18C"&&xw=="18B"){
                    cout<<"11";
                }
                else if(rw=="18D"&&xw=="18E"){
                    cout<<"11";
                }
                else if(rw=="18E"&&xw=="18D"){
                    cout<<"11";
                }
                else if(rw=="18C"&&xw=="18A"){
                    cout<<"10";
                }
                else if(rw=="18A"&&xw=="18C"){
                    cout<<"10";
                }
                else cout<<"00";
            }

        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
